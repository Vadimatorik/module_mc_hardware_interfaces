#pragma once

#include <stdint.h>

enum class EC_SPI_BASE_RESULT {
    OK                  = 0,            // Операция успешна произведена.
    TIME_OUT            = 1,            // Был произведён выход по истечении времени ожидания.
    LENGTH_ERROR        = 2             // Попытка передать/принять пакет 0-й длины.
};

//**********************************************************************
// SPI в режиме мастера, транзакции по 8 бит.
//**********************************************************************
class spi_master_8bit_base {
public:
    //**********************************************************************
    // Метод должен:
    // 1. Отключить SPI.
    // 2. Заполнить все регистры.
    //**********************************************************************
    virtual void reinit ( void ) const = 0;

    //**********************************************************************
    // Методы должены включать/отключать SPI (не перетерая поля регистров).
    //**********************************************************************
    virtual void on     ( void ) const = 0;
    virtual void off    ( void ) const = 0;

    //**********************************************************************
    // p_array_tx   -   указатель на массив, который требуется передать
    //                  по spi. Указатель на 0-й передаваемый байт
    //                  ( байт, с которого будет начата передача ).
    // length       -   длина посылки. length != 0! length >= 1!
    //
    // timeout_ms   -   если посылка не была передана в течении этого времени
    //                  ( в миллисекундах ), то выходим с ошибкой.
    //
    // ЗАМЕЧАНИЕ: входной прием не ведется (входные данные просто теряются)!
    //**********************************************************************
    virtual EC_SPI_BASE_RESULT tx ( const uint8_t* const  p_array_tx, const uint16_t& length, const uint32_t& timeout_ms ) const = 0;

    //**********************************************************************
    // p_array_tx   -   указатель на массив, который требуется передать
    //                  по spi. Указатель на 0-й передаваемый байт
    //                  ( байт, с которого будет начата передача ).
    //
    // p_array_rx   -   указатель на массив, в который будет
    //                  осуществляться прием по spi.
    //                  Указатель на 0-й принемаемый байт
    //                  ( первый пришедший байт ).
    //
    // length       -   длина посылки. length != 0! length >= 1!
    //
    // timeout_ms   -   если посылка не была передана в течении этого времени
    //                  ( в миллисекундах ), то выходим с ошибкой.
    //
    // ЗАМЕЧАНИЕ: p_array_tx может быть равен p_array_rx. Тогда
    // принятые данные перезапишут массив исходящих данных!
    //**********************************************************************
    virtual EC_SPI_BASE_RESULT tx ( const uint8_t* const  p_array_tx, uint8_t* p_array_rx, const uint16_t& length, const uint32_t& timeout_ms ) const = 0;

    //**********************************************************************
    // p_item_tx    -   указатель на переменную, которая будет передаваться
    //                  count раз.
    //
    // count        -   количество транзакций (сколько раз передать байт).
    //                  count != 0! count >= 1!
    //
    // timeout_ms   -   если посылка не была передана в течении этого времени
    //                  ( в миллисекундах ), то выходим с ошибкой.
    //
    // Передаем 1 байт count раз.
    //**********************************************************************
    virtual EC_SPI_BASE_RESULT tx_one_item ( const uint8_t p_item_tx, const uint16_t count, const uint32_t timeout_ms ) const = 0;

    //**********************************************************************
    // p_array_rx   -   указатель на массив, в который будет
    //                  осуществляться прием по spi.
    //                  Указатель на 0-й принимаемый байт
    //                  ( первый пришедший байт ).
    //
    // length       -   количество принимаемых байт.
    //
    // timeout_ms   -   если посылка не была передана в течении этого времени
    //                  ( в миллисекундах ), то выходим с ошибкой.
    //
    // value_out    -   значение, которое будет отправляться по TX
    //                  ( если будет использоваться ).
    //**********************************************************************
    virtual EC_SPI_BASE_RESULT rx ( uint8_t* p_array_rx, const uint16_t& length, const uint32_t& timeout_ms, const uint8_t& out_value = 0xFF ) const = 0;
};
