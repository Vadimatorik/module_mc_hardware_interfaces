#pragma once

#ifdef __cplusplus

#include "mc_hardware_interfaces_base.h"

/*!
 * Класс предназначен для использования нескольких каналов ADC
 * в режиме непрерывного преобразования.
 */
class AdcMultiChannelBase {
public:
	/*!
	 * Сбрасывает текущие настройки ADC и инициализирует его заново.
	 * После инициализации ADC остается отключенным.
	 *
	 * Замечание: управление тактовым сигналом аппаратного
	 * модуля осуществляется внутри метода автоматически.
	 *
	 * \param[in]	numberCfg		-	выбранный режим работы.
	 *
	 * 	\return		{	BASE_RESULT::OK			-	инициализация прошла успешно.
	 *					BASE_RESULT::INPUT_VALUE_ERROR	-	несуществующий номер конфигурации.
	 *					BASE_RESULT::ERROR_INIT	-	в противном случае.	}
	 */
	virtual BaseResult		reinit								(	uint32_t		numberCfg = 0	)		= 0;

	/*!
	 * Инициирует непрерывное преобразование на канале.
	 *
	 * \return		{	BASE_RESULT::OK			-	последовательность преобразований
	 *												была успешно начата.
	 *					BASE_RESULT::ERROR_INIT	-	в противном случае.	}
	 */
	virtual BaseResult		startContinuousConversion			(	void	)								= 0;

	/// Останавливает непрерывное преобразование на канале.
	virtual void			stopContinuousConversion			(	void	)								= 0;

	/// Возвращает результат измерения.
	/// \return		{	Результат измерения напряжения на канале.	}
	virtual BaseResult		getMeasurement						(	uint32_t		numberChannel,
																	uint32_t&			returnedValue	)	= 0;

};

#endif

/*!
 * 	@startuml
 *
 * 	interface AdcMultiChannelBase {
 *		{abstract}{method}+	BaseResult		reinit					( uint32_t		numberCfg = 0 )
 *		{abstract}{method}+	BaseResult		startContinuousConversion	( void )
 *		{abstract}{method}+	void			stopContinuousConversion	( void )
 *		{abstract}{method}+	BaseResult		getMeasurement			( uint32_t		numberChannel,
 *													\t\t\t\t\t\t\t\t  uint32_t&		returnedValue )
 *	}
 *
 *	@enduml
 */
