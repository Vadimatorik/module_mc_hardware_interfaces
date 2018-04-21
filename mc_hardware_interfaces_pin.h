#pragma once

#include <stdint.h>

/*!
 * Класс предназначен для управления одной линией ввода/вывода.
 * Вывод должен быть заранее настроен на выход или вход с нужными
 * параметрами.
 */
class PinBase {
public:
	/// Устанавливает вывод в логическую единицу.
	virtual void	set				( void )					= 0;

	/// Устанавливает вывод в логический ноль.
	virtual void	reset			( void )					= 0;

	/// Инвертирует значение на выходе.
	virtual void	toggle			( void )					= 0;

	/// Устанавливает на выводе заданное состояние.
	/// \param[in]	state		-	устанавливаемое состояние.
	virtual void	set				( bool state )				= 0;

	/// Устанавливает на выводе заданное состояние.
	/// \param[in]	state		-	устанавливаемое состояние.
	virtual void	set				( int state )				= 0;

	/// Устанавливает на выводе заданное состояние.
	/// \param[in]	state		-	устанавливаемое состояние.
	virtual void	set				( uint8_t state )			= 0;

	/// Возвращает состояние на входе вывода.
	/// \return		{Состояние на входе вывода.}
	virtual bool	read			( void )					= 0;

};

/*!
 * Класс предназначен для смены назначение вывода
 * в процессе выполнения программы.
 */
class PinMultifuncBase {
public:
	/*!
	 * Изменяет назначение вывода на согласно требуемому режиму.
	 * \param[in]	numberCfg	-	номер требуемого режима.
	 * \return		{	true	-	если требуемый режим существует
	 *								и был успешно выбран.
	 *					false	-	в противном случае.	}
	 */
	virtual bool	reinit			( uint32_t numberCfg )		= 0;

};

/*!
 * Класс предназначен для работы с прерываниями,
 * возникающими на линии в режиме работы на вход.
 */
class PinMultifuncItBase {
public:
	/*!
	 * Возвращает флаг зафиксированного прерывания на выводе.
	 * \return		{	true	-	прерывание было зафиксировано.
	 *					false	-	в противном случае.	}
	 */
	virtual bool	checkIt			( void )					= 0;

	/// Сбрасывает флаг зафиксированного прерывания на выводе.
	virtual void	clearIt			( void )					= 0;
};


