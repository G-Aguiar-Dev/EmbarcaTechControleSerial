#include <stdio.h>
#include "pico/stdlib.h"

#define gpio_buzzer 21
#define gpio_led_green 11
#define gpio_led_blue 12
#define gpio_led_red 13

void inicializa_pinos()
{
    gpio_init(gpio_led_green);
    gpio_set_dir(gpio_led_green, GPIO_OUT);

    gpio_init(gpio_led_blue);
    gpio_set_dir(gpio_led_blue, GPIO_OUT);

    gpio_init(gpio_led_red);
    gpio_set_dir(gpio_led_red, GPIO_OUT);

    gpio_init(gpio_buzzer);
    gpio_set_dir(gpio_buzzer, GPIO_OUT);
}

<<<<<<< Updated upstream
// funcao para controlar os leds
=======
//Função para desligar todos os LEDS
void desligar_leds()
{
    gpio_put(gpio_led_blue, 0);
    gpio_put(gpio_led_green, 0);
    gpio_put(gpio_led_red, 0);
}

// Função para controlar os leds
>>>>>>> Stashed changes
void piscar_leds(char tecla)
{
    desligar_leds(); // Garante que apenas um LED estará ligado
    switch (tecla)
    {
    case 1: // LED Verde
<<<<<<< Updated upstream
    
        break;
    case 2: // LED Azul

        break;
    case 3: // LED Vermelho

=======
        gpio_put(gpio_led_green, true);
        break;
    case 2: // LED Azul
        gpio_put(gpio_led_blue, true);
        break;
    case 3: // LED Vermelho
        gpio_put(gpio_led_red, true);
>>>>>>> Stashed changes
        break;
    case 4: // Todos os LEDs

        break;
    default:
        printf("Comando inválido para LEDs\n");
    }
}

// Funcao para ativar o Buzzer por 2 segundos
void tocar_buzzer()
{
    gpio_put(gpio_buzzer, true);  // Ligar o buzzer
    sleep_ms(2000);               // Buuzer ativo por 2 segundos
    gpio_put(gpio_buzzer, false); // Desativar buzzer
}

void desligar_leds()
{
    // Desliga os leds
}

// Função auxiliar para mapear strings em valores inteiros
int mapear_comando(const char *comando)
{
    if (strcmp(comando, "GREEN") == 0)
        return 1;
    if (strcmp(comando, "BLUE") == 0)
        return 2;
    if (strcmp(comando, "RED") == 0)
        return 3;
    if (strcmp(comando, "WHITE") == 0)
        return 4;
    if (strcmp(comando, "BUZZER") == 0)
        return 5;
    if (strcmp(comando, "OFF") == 0)
        return 6;
    return 0; // Comando inválido
}

void bootsel()
{
<<<<<<< Updated upstream
    // Verifica se o botão de seleção foi pressionado
=======
    reset_usb_boot(0, 0); // Reinicia no modo BOOTSEL
>>>>>>> Stashed changes
}

int main()
{
    stdio_init_all();
    inicializa_pinos();

    char entrada[20];

    printf("Digite um comando (GREEN, BLUE, RED, WHITE, BUZZER, OFF): \n");

    while (1)
    {
        // Recebe comandos via UART
        scanf("%19s", entrada); // Lê o comando enviado pelo monitor serial

        int comando = mapear_comando(entrada); // Converte o comando para um valor numérico

        switch (comando)
        {
<<<<<<< Updated upstream
        case 1:                   // GREEN
        case 2:                   // BLUE
        case 3:                   // RED
        case 4:                   // WHITE
            piscar_leds(comando); // Controla os LEDs
=======
        case 1:                             // GREEN
        case 2:                             // BLUE
        case 3:                             // RED
        case 4:                             // WHITE
            piscar_leds(comando);           // Controla os LEDs
>>>>>>> Stashed changes
            printf("ON: %s\n", entrada);
            break;
        case 5:             // BUZZER
            tocar_buzzer(); // Ativa o buzzer
            printf("ON: %s\n", entrada);
            break;
        case 6:              // OFF
            desligar_leds(); // Desliga todos os LEDs
            printf("LEDS: %s\n", entrada);
            break;
<<<<<<< Updated upstream
=======
        case 7:                             // BOOTSEL
            bootsel();
            printf("ON: %s\n", entrada);
            break;
>>>>>>> Stashed changes
        default:
            printf("Comando inválido\n");
        }
        sleep_ms(100); // Pequeno atraso para estabilidade
    }
}
