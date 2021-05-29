/**  @file
*   @author Yurasov V.D.
*  @version 1.0.0
*   @date 29.05.2021
*   @brief Заголовочный файл для модуля modAlphaCipher
*/

#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
#include <iostream>
#include <cctype>
using namespace std;

/** @class modAlphaCypher
 * @author Yurasov V.D.
 * @date 29.05.2021
 * @file modAlphaCipher.h
 * @brief Шифрование методом Гронсфельда
 * @details Для зашифрования и расшифрования сообщения предназначены методы encrypt и decrypt. Текст на обработку передается в качестве параметра.
 * @warning Реализация только для русского языка!
 */

class modAlphaCypher
{
private:
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///алфавит по порядку
    std::string numalpha = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; ///кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha);
    std::wstring wa = codec.from_bytes(numalpha);
    std::map <char,int> alphaNum; ///ассоциативный массив "номер по символу"
    std::vector <int> key; ///ключ
    std::vector<int> convert(const std::string& s); ///преобразование строка-вектор
    std::string convert(const std::vector<int>& v); ///преобразование вектор-строка
     /** @brief Метод, проверяющий текст на валидность
     * @param [in] s Текст на русском языке
     * @return result
     */
    std::string getValidOpenText(const std::string & s);
     /** @brief Метод , проверяющий расшифрованный текст на валидность
     * @param [in] s Расшифрованный текст на русском языке
     * @return result
     */
    std::string getValidCypherText(const std::string & s);
     /** @brief Метод, проверяющий зашифрованный текст на валидность
     * @param [in] s Зашифрованный текст на русском языке
     * @return result
     */
    std::string getValidKey(const std::string & s);
public:
    modAlphaCypher()=delete; ///запретим конструктор без параметров
     /** @brief Конструктор создания объекта, хранящего в себе ключ шифрования
     * @param [in] text Текст на русском языке
     * @warning Текст не должен быть пустым и не должен содержать пробелы. В тексте могут содержаться знаки препинания и цифры.
     */
    modAlphaCypher(const std::string& skey); ///конструктор для установки ключа
     /** @brief Зашифрование
     * @param [in] text Открытый текст на русском языке
     * @warnings Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки препинания и цифры.
     * @return result Зашифрованный текст
     */
    std::string encrypt(const std::string& open_text); ///зашифрование
     /** @brief Расшифрование
     * @param [in] text Зашифрованный текст на русском языке
     * @warning Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки препинания и цифры.
     * @return result Расшифрованный текст
     */
    std::string decrypt(const std::string& cypher_text);///расшифрование
};

class cypher_error: public std::invalid_argument
{
public:
    explicit cypher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cypher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
