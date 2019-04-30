/**
* @file can.h
* @brief Ten plik zawiera delkarację funkcji dotyczących CAN
*
* @author Piotr Brytan 
*
* @date 31/04/2019
*/
#ifndef MAIN_INC_CAN_H_
#define MAIN_INC_CAN_H_

#include "includes.h"

/**
 * @brief Moduł rozróżniający zadania ramek
 *
 * Funkcja ta przyjmuje jako parametr ID ramki CAN i na jej podstawie wykonuje przypisane do ID zadanie.
* @param id ID otrzymanej ramki CAN
*/
void route_module(uint32_t id);

/**
 * @brief Instalacja/uruchomienia CAN drivera
 *
 * Funkcja ta instaluje oraz uruchamia driver CAN. 
*/
void can_start_app(void);

/**
 * @brief Usunięcie/zatrzymanie CAN drivera.
 *
 * Funkcja ta zatrzymuje i usuwa driver CAN.
*/
void can_stop_app(void);

/**
 * @brief Odbieranie ramek CAN
 *
 * Funkcja ta odbiera ramki CAN oraz wypusuje je na konsoli. 
*/
void can_receive_task(void *arg);

/**
 * @brief Status diody 
 *
 * Funkcja ta przesyła co sekundę stan diody w postaci ramki CAN. 
*/
void can_status(void);

#endif /* MAIN_INC_CAN_H_ */
