HAL_CAN_StateTypeDef fct_transmit(UART_HandleTypeDef *huart, uint8_t info3[]);

HAL_StatusTypeDef traitement(uint8_t *zeData);

HAL_StatusTypeDef init(UART_HandleTypeDef *huart);

//float calculdata(float ladata[],uint8_t PID);
