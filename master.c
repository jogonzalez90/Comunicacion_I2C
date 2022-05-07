#include <master.h>

void main()
{

   #USE I2C(MASTER, SDA= PIN_C4, SLOW, SCL=PIN_C3) 
   
   //CONFIGURAMOS PUERTOS
   
   SET_TRIS_B(0B00000011);//PINES 0 Y 1 COMO ENTRADA
   SET_TRIS_D(255);//TODO PUERTO COMO ENTRADA
   
   #DEFINE SEL1 PIN_B0
   #DEFINE SEL2 PIN_B1
   
   //SALIDAS A 0
   OUTPUT_LOW(PIN_B2);
   OUTPUT_LOW(PIN_B3);
   OUTPUT_LOW(PIN_B4);
   OUTPUT_LOW(PIN_B5);
   OUTPUT_LOW(PIN_B6);
   OUTPUT_LOW(PIN_B7);
   
   INT DATO=0;
   
   while(TRUE)
   {
      IF(INPUT(SEL1)==1)
      {
         IF(INPUT(SEL2)==1)
         {
            DATO= INPUT_D();
            I2C_START();// condición de inicio exclusivo master
            I2C_WRITE(0X10);// direccionamiento ESCLAVO DOS
            I2C_WRITE(DATO);//ESCRIBIMOS DATO A ENVIAR
            I2C_STOP();//LANZA CONDICION DE PARADA EXCLUSIVO MASTER
            DELAY_MS(100);
            
         }
         ELSE
         {
            DATO= INPUT_D();
            I2C_START();// lanza condición de inicio exclusivo master
            I2C_WRITE(0X20);// direccionamiento ESCLAVO UNO
            I2C_WRITE(DATO);//ESCRIBIMOS DATO A ENVIAR
            I2C_STOP();// LANZA CONDICION DE PARADA EXCLUSIVO MASTER
            DELAY_MS(100);
            
         }
      }
   }

}
