/*
 * This file is part of Cleanflight and Magis.
 *
 * Cleanflight and Magis are free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight and Magis are distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif 

typedef enum {
    ADC_BATTERY = 0,
    ADC_RSSI = 1,
    ADC_EXTERNAL1 = 2,
    ADC_CURRENT = 3,
    ADC_CHANNEL_MAX = ADC_CURRENT
} AdcChannel;

#define ADC_CHANNEL_COUNT (ADC_CHANNEL_MAX + 1)

typedef struct adc_config_s {
        uint8_t adcChannel;         // ADC1_INxx channel number
        uint8_t dmaIndex;           // index into DMA buffer in case of sparse channels
        bool enabled;
        uint8_t sampleTime;
} adc_config_t;

typedef struct drv_adc_config_s {
        bool enableVBat;
        bool enableRSSI;
        bool enableCurrentMeter;
        bool enableExternal1;
} drv_adc_config_t;

void adcInit(drv_adc_config_t *init);
uint16_t adcGetChannel(uint8_t channel);

#ifdef __cplusplus
}
#endif 
