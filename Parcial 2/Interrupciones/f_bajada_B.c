#define F_CPU 16000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
     // Deshabilitar INT0 temporalmente
    EIMSK &= ~(1 << INT0);

    // Esperar 20 ms para eliminar el rebote
    _delay_ms(150);

    // Comprobar si el botón sigue presionado
   if (!(PIND & (1 << PD2)))
{
    PORTB ^= (1 << PORTB5);
}

    // Limpiar bandera de interrupción
    EIFR = (1 << INTF0);

    // Volver a habilitar INT0
    EIMSK |= (1 << INT0);
}

int main(void)
{
    DDRB |= (1 << DDB5);       // PB5 como salida

    DDRD &= ~(1 << DDD2);     // PD2 como entrada
    PORTD |= (1 << PORTD2);   // Habilita Pull-up

    EICRA = (1 << ISC01) | (0 << ISC00);
    EIFR = (1 << INTF0);      // Limpia la bandera de interrupción
    EIMSK = (1 << INT0);      // Activa INT0

    sei();                    // Habilita interrupciones globales

    while (1)
    {

    }
}
