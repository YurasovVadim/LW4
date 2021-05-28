/**  @file
* *  @author Юрасов В.Д.
* *  @version 1.0.0
* *  @date 29.05.2021
* *  @brief Заголовочный файл для модуля Marsh
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

/** @class modMarshCypher
 ** @author Юрасов В.Д.
 ** @date 29.05.2021
 ** @file modMarsh.h
 ** @brief Шифрование методом маршрутной перестановки
 ** @detalies Для зашифрования и расшифрования сообщения предназначены методы encrypt и decrypt. Текст передаётся на последовательное зашифрование и расшифрование. Доступна отмена выполнения программы.
 ** @warnings Реализован только английский язык
 */

class modMarshCypher
{
private:
    int key;
     /** @brief Метод класса, проверяющий текс на валидность
     ** @param [in] s Текст на русском языке
     ** @return result
     */
    std::string getValidOpenText(const std::string & s);
     /** @brief Метод класса, проверяющий расшифрованный текст на валидность
     ** @param [in] s Зашифрованный текст на английском языке
     ** @return result
     */
    std::string getValidCypherText(const std::string & s);
public:
    modMarshCypher()=delete;
    modMarshCypher(const string& key1);
     /** @brief Зашифрование
     ** @param [in] text Открытый текст на английском языке
     ** @warnings Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки препинания и цифры.
     ** @return result Зашифрованный текст
     ** @throw cipher_error Текст является пустой строкой
     */
    std::string encrypt(const std::string& open_text);
      /** @brief Расшифрование
     ** @param [in] text Зашифрованный текст на английском языке
     ** @warnings Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cipher_error Текст является пустой строкой
     */
    std::string decrypt(const std::string& cipher_text);
};
 	 /** @class cypher_error
     ** @file Marsh.h
     ** @brief Класс вызова исключений 
     */

class cypher_error: public std::invalid_argument
{
public:
 	 /** @brief Валидация текста
     ** @param [in] what_arg После проверки текста при помощи getValidText, если возвращенный параметр вызывает исключения, причина вызова исключений передается в качестве параметра функцию.
     ** @warnings Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки препинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cypher_error Текст является пустой строкой
     */
    explicit cypher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
     /** @brief Валидация текста
     ** @param [in] what_arg После проверки номера операции, если возвращенный параметр вызывает исключения, причина вызова исключений передается в качестве параметра функцию.
     ** @warnings Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cypher_error Текст является пустой строкой
     */
    explicit cypher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
