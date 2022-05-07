#include <slave_1.h>

void main()
{
   /*
   ENLACE USADO
   https://www.youtube.com/watch?v=sxpla8SAHsE
   */
   
   #USE I2C (SLAVE, SDA= PIN_C4, SLOW, SCL=PIN_C3, ADDRESS= 0X20)
   
   INT DATO=0;
   
   //CONFIGURAMOS PUERTOS
   SET_TRIS_B(0);
   
   //DEJAMOS SALIDAS EN 0
   OUTPUT_B(0);

   while(TRUE)
   {
      IF(I2C_POLL())
      {
         DATO= I2C_READ();//LEE EL BYTE DE LA INTERFAZ I2C
         OUTPUT_B(DATO);
      }
   }

}
