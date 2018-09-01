#pragma once

#ifdef __cplusplus

#include "platform.h"

#ifdef HAL_TIM_MODULE_ENABLED

#include "timer_counter.h"
#include "mc_hardware_interfaces_timer_comp_one_channel.h"

struct timCompOneChannelCfg {
	// Используемый таймер.
	TIM_TypeDef*					tim;

	const clkTimBaseCfg*			const cfg;
	uint32_t						countCfg;

	// Параметры выходного канала.
	uint8_t							outChannel;		// TIM_CHANNEL_x.
	uint32_t						polarity;		// TIM_OCPOLARITY_LOW  / TIM_OCPOLARITY_HIGH.

};

class TimCompOneChannel : public TimCompOneChannelBase {
public:
	TimCompOneChannel( const timCompOneChannelCfg* const cfg );

	BaseResult		reinit					( uint32_t numberCfg = 0 );

	BaseResult		on						( void );
	void			off						( void );

private:
	const timCompOneChannelCfg*		const cfg;

	TIM_HandleTypeDef				tim;
	TIM_OC_InitTypeDef				timCh;
};

#endif

#endif
