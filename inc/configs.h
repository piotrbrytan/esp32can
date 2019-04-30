/**
* @file configs.h 
* @brief Ten plik zawiera dane konfiguracyjne serwera mqtt, wifi, piny do jakich podłączony jest moduł CAN.
*
* @author Piotr Brytan 
*
* @date 31/04/2019
*/
#ifndef MAIN_INCLUDE_CONFIGS_H_
#define MAIN_INCLUDE_CONFIGS_H_

#define BUILDIN_LED             2         /**< Wbudowana na płytce dioda */
#define CONFIG_WIFI_SSID        ""        /**< SSID */
#define CONFIG_WIFI_PASSWORD    ""        /**< hasło wifi */
#define CONFIG_BROKER_URL       "mqtt://" /**< adres serwera mqtt */ 
#define CAN_TX_GPIO             21        /**< CAN TX */      
#define CAN_RX_GPIO             22        /**< CAN RX */     

#endif /* MAIN_INCLUDE_CONFIGS_H_ */
