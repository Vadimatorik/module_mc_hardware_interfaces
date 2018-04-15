#pragma once

#include <stdint.h>

#ifdef __cplusplus

class DacOneChannelBase {
public:
	//**********************************************************************
	// Метод должен:
	// 1. Отключить DAC.
	// 2. Сконфигурировать DAC и его канал в заданном режиме.
	// 3. Включить его.
	//**********************************************************************
	virtual bool	reinit			( void )			const = 0;

	//**********************************************************************
	// Выставление заданного значения на канал.
	//**********************************************************************
	virtual void	setValue		( uint32_t& value )			const = 0;
	virtual void	setValue		( const uint32_t value )	const = 0;
};

#endif
