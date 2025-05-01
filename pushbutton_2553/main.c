
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD; // WATCHDOG TIMER KAPATIR

  // LED ÇIKIŞ AYALARI
  P2DIR |= BIT1; // P2.1 YEŞİL LED 
  
  // BUTON GİRİŞ AYARLARI
  P2DIR &= ~BIT3; // P 1.3 GİRİŞİ => S2 BUTONU
  P1REN |= BIT3; //  PULL UP/DOWN DİRENCİ ETKİN
  P1OUT |= BIT3; // PULL UP ETKİNLEŞTİR BUTONA BASILMADIĞINDA HİGH BASILDIĞINDA LOW

  while(1)
  {
    if((P1IN & BIT3) == 0 ) // BUTONA BASILMA DURUMU
    P2OUT |= BIT1; // P 2.1 LEDİNİ YAK
    
    else P2OUT &= ~BIT1; // P2.1 LEDİNİ SÖNDÜR

  } 
}
