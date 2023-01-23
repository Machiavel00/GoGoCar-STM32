//#include "stm32f1xx_hal_uart.h"
#include "main.h"

UART_HandleTypeDef *huart2;

HAL_StatusTypeDef init(UART_HandleTypeDef *huart)
{
	huart2=huart;
	return HAL_OK;
}

HAL_StatusTypeDef fct_transmit(UART_HandleTypeDef *huart,uint8_t info3[])
{
	if (HAL_UART_Transmit(huart,info3,sizeof(uint8_t),100) ==HAL_OK)
		{
			return HAL_OK;
		}
	else{
		return HAL_ERROR;
	}
}

/*
float calculdata(float ladata[],uint8_t PID){
	switch(PID)
	{
	case 13: ;
		float val=ladata[0];
		return val;
	case 47: ;
		float val1=(ladata[0]/255);
		return val1;
	case 33: ;
		float val2=(ladata[0]*256+ladata[1]);
		return val2;
	case 31: ;
		float val3=ladata[0]*256+ladata[1];
		return val3;
	case 94: ;
		float val4=((ladata[0]*256+ladata[1])/20);
		return val4;
	case 103:	;
		float val5=(ladata[1]-40);
		return val5;
	case 92: ;
		float val6=(ladata[0]-40);
		return val6;
	case 90: ;
		float val7=(ladata[0]*100/255);
		return val7;
	case 5: ;
		float val8=(ladata[0]-40);
		return val8;
	}
}
*/

HAL_StatusTypeDef carburant(int carbura)
{

	switch(carbura)
	{
	case 1: ;
		char carb[]={"Gazoil"};
		fct_transmit(huart2, (uint8_t*)carb);
		return HAL_OK;
	case 2: ;
		char carb1[]={"Methanol"};
		fct_transmit(huart2, (uint8_t*)carb1);
		return HAL_OK;
	case 3: ;
		char carb2[]="Ethanol";
		fct_transmit(huart2, (uint8_t*)carb2);
		return HAL_OK;
	case 4: ;
		char Vin[]="Diesel";
		fct_transmit(huart2, (uint8_t*)Vin);
		return HAL_OK;
	case 5:	;
		char carb3[]="LPG";
		fct_transmit(huart2, (uint8_t*)carb3);
		return HAL_OK;
	case 6: ;
		char carb4[]="CNG";
		fct_transmit(huart2, (uint8_t*)carb4);
		return HAL_OK;
	case 7: ;
		char hunt[]="Propane";
		fct_transmit(huart2, (uint8_t*)hunt);
		return HAL_OK;
	case 8: ;
		char carb5[]="Electrique";
		fct_transmit(huart2, (uint8_t*)carb5);
		return HAL_OK;
	case 9: ;
		char carb6[]="Ethanol";
		fct_transmit(huart2, (uint8_t*)carb6);
		return HAL_OK;
	case 10: ;
		char carb7[]="Bicarburant au gazoil";
		fct_transmit(huart2, (uint8_t*)carb7);
		return HAL_OK;
	case 11: ;
		char carb8[]="Bicarubrant Methanol";
		fct_transmit(huart2, (uint8_t*)carb8);
		return HAL_OK;
	case 12: ;
		char carb9[]="Bicarburant Ethanol";
		fct_transmit(huart2, (uint8_t*)carb9);
		return HAL_OK;
	case 13: ;
		char carb10[]="Bicarburant LPG";
		fct_transmit(huart2, (uint8_t*)carb10);
		return HAL_OK;
	case 14: ;
		char carb11[]="Bicarburant CNG";
		fct_transmit(huart2, (uint8_t*)carb11);
		return HAL_OK;
	case 15: ;
		char carb12[]="Bicarburant Propane";
		fct_transmit(huart2, (uint8_t*)carb12);
		return HAL_OK;
	case 16: ;
		char carb13[]="Bicarburant Electrique";
		fct_transmit(huart2, (uint8_t*)carb13);
		return HAL_OK;
	case 17: ;
		char carb14[]="Bicarburant Electrique et combustion";
		fct_transmit(huart2, (uint8_t*)carb14);
		return HAL_OK;
	case 18: ;
		char carb15[]="Hybride gazoil";
		fct_transmit(huart2, (uint8_t*)carb15);
		return HAL_OK;
	case 19: ;
		char carb16[]="Hybride Ethanol";
		fct_transmit(huart2, (uint8_t*)carb16);
		return HAL_OK;
	case 20: ;
		char carb17[]="Hybride Diesel";
		fct_transmit(huart2, (uint8_t*)carb17);
		return HAL_OK;
	case 21: ;
		char carb18[]="Hybride Electrique";
		fct_transmit(huart2, (uint8_t*)carb18);
		return HAL_OK;
	case 22: ;
		char carb19[]="Hybride electrique et combustion";
		fct_transmit(huart2, (uint8_t*)carb19);
		return HAL_OK;
	case 23: ;
		char carb20[]="Hybride regeneratif";
		fct_transmit(huart2, (uint8_t*)carb20);
		return HAL_OK;

	default: ;
		char err[]="inconnu";
		fct_transmit(huart2, (uint8_t*)err);
		return HAL_ERROR;

	}
}




HAL_StatusTypeDef traitement(uint8_t *ZeData)
{
	/*
	 *il se peut que deux messages soient présent dans Data_converti et qu'elle soit uniformément découpée de [0;3] U [4;7]
	 *
	 *
	 *
	 * int Data_converticonv1=0;
	 * int Data_converticonv2=0;
	 * int i=0;
	 *
	 * for(i;i<3;i++)
	 * {
	 * Data_converticonv=Data_converticonv1+Data_converti[i];
	 * }
	 *
	 * for(i;i<7;i++)
	 * {
	 * Data_converticonv2=Data_converticonv2+Data_converti[i];
	 * }
	 *
	 * for(i=0;i<1;i++)
	 * {
	 * if(i==0)
	 * {
	 * mettre le switch avec Data_converticonv1
	 * }
	 *
	 * if(i==1)
	 * {
	 * mettre le switch avec Data_converticonv2
	 * }
	 *
	 * }
	 * il se peut également que la data récupère absolument tout ce qui est présent à l'intérieur car il y a deux fifo et la data est répartie en 2 modules de 4 cases
	 * en quel cas, il faut appliquer la fonction sur chaque case/info de chaque fifo
	 * for(i;i<3;i++)
	 * {
	 * switch(
	 * }
	 *
	 *
	 *
	 *
	 *
	*/
	int PID=(int)ZeData[2];
	uint8_t Data_converti;

	switch(PID)
	{

			case 13:
				Data_converti=ZeData[3];
				if(Data_converti>255||Data_converti<0)
				{
					return HAL_ERROR;
				}
				else
				{
					printf( "votre vitesse est de : %d\n", Data_converti);
					fct_transmit(huart2,&Data_converti);
				return HAL_OK;
				}
			case 47:
				Data_converti=ZeData[3];
				if(Data_converti>100 || Data_converti<0)
				{
				return HAL_ERROR;
				}
				else
					{
						printf("votre niveau d'essence est de : %d\n", Data_converti);
						fct_transmit(huart2,&Data_converti);
					return HAL_OK;
					}
			case 33:
				Data_converti=ZeData[3]+ZeData[4];
				if(Data_converti>65535 || Data_converti<0)
				{
					return HAL_ERROR;
				}
				else
				{
					printf("depuis votre dernier malfonctionnement vous avez parcouru  : %d \n",Data_converti);
					fct_transmit(huart2,&Data_converti);
				return HAL_OK;
				}
			case 81:
				Data_converti=ZeData[3];
				carburant((int)Data_converti);
				return HAL_OK;
			case 31:
				Data_converti=(ZeData[3]*256+ZeData[4]);
				if(Data_converti>65535 || Data_converti<0)
				{
					return HAL_ERROR;
				}
				else
				{
					printf("Depuis le demarrage, il s'est ecoule s : %d \n",Data_converti);
					fct_transmit(huart2,&Data_converti);
				return HAL_OK;
				}
			case 94:
				Data_converti=((ZeData[3]*256+ZeData[4])/20);
				if(Data_converti>65535 || Data_converti<0)
				{
					return HAL_ERROR;
				}
				else
				{
					printf("en l/h, vous consommez : %d\n", Data_converti);
					fct_transmit(huart2,&Data_converti);
				return HAL_OK;
				}
			case 103:
				Data_converti=(ZeData[4]-40);
				if(Data_converti>215 || Data_converti<-40)
				{
					return HAL_ERROR;
				}
				else
				{
					printf("la temperature de l'eau est a %d\n",Data_converti);
					fct_transmit(huart2,&Data_converti);
				return HAL_OK;
				}
			case 92:
				Data_converti=(ZeData[3]-40);
				if(Data_converti>210 || Data_converti<-40)
				{
					return HAL_ERROR;
				}
				else
				{
					printf("la temperature de l'huile %d \n",Data_converti);
					fct_transmit(huart2,&Data_converti);
				return HAL_OK;
				}
			case 90:
				Data_converti=(ZeData[3]*100/255);
				if(Data_converti>100 || Data_converti<-0)
				{
					return HAL_ERROR;
				}
				else
				{
					printf("la position de la pedale en pourcent %d \n", Data_converti);
					fct_transmit(huart2,&Data_converti);
				return HAL_OK;
				}
				case 5:
				Data_converti=(ZeData[3]-40);
				if(Data_converti>215 || Data_converti<-40)
				{
					return HAL_ERROR;
				}
				else
				{
					printf("la temperature du liquide de refroidissement %d \n",Data_converti);
					fct_transmit(&huart2,&Data_converti);
				return HAL_OK;
				}
			default: ;
				char info[]={"ce n'est pas le PID qu'on recherche"};
				fct_transmit(huart2, (uint8_t*)info);
		}

}
