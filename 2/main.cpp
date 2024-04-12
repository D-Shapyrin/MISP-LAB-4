/**
* @file modAlphaCipher.h
* @author Shapyrin D.A.
* @version 1.0.0
* @brief Заголовочный файл для модуля modAlphaCipher
* @date 12.04.2024
* @copyright ИБСТ ПГУ
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

class modAlphaCipher
{
private:
    int key;
    /** @brief Метод класса, проверяющий текс на валидность
     ** @param [in] s Текст на русском языке
     ** @return result
     */
    std::string getValidOpenText(const std::string& s);
    /** @brief Метод класса, проверяющий расшифрованный текст на валидность
     ** @param [in] s Зашифрованный текст на английском языке
     ** @return result
     */
    std::string getValidCipherText(const std::string& s);
public:
    modAlphaCipher() = delete;
    modAlphaCipher(const string& key1);
    /** @brief Зашифрование
     ** @param [in] text Открытый текст на английском языке
     ** @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Зашифрованный текст
     ** @throw cipher_error Если в качестве текста ввеена пустая строка
     */
    std::string encrypt(const std::string& open_text);
    /** @brief Расшифрование
     ** @param [in] text Зашифрованный текст на английском языке
     ** @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cipher_error Если в качестве текста ввеена пустая строка
     */
    std::string decrypt(const std::string& cipher_text);
};
/** @class cipher_error
 ** @file modAlphaCipher.h
 ** @brief Класс вызова исключений
 */
class cipher_error : public std::invalid_argument
{
public:
    /** @brief Валидация текста
     ** @param [in] what_arg После проверки текста при помощи getValidText, если возвращенный параметр вызывает исключения, причина вызова исключений передается в качестве параметра функцию.
     ** @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cipher_error Если в качестве текста ввеена пустая строка
     */
    explicit cipher_error(const std::string& what_arg) :
        std::invalid_argument(what_arg) {}
    /** @brief Валидация текста
     ** @param [in] what_arg После проверки номера операции, если возвращенный параметр вызывает исключения, причина вызова исключений передается в качестве параметра функцию.
     ** @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cipher_error Если в качестве текста ввеена пустая строка
     */
    explicit cipher_error(const char* what_arg) :
        std::invalid_argument(what_arg) {}
};



