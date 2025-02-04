# EmbarcaTech_OneShot

## 📌 DESCRIÇÃO
Este projeto implementa um sistema de temporização para acionamento de LEDs utilizando o Raspberry Pi Pico W e um botão pushbutton. O sistema usa a função add_alarm_in_ms() do Pico SDK para gerenciar um temporizador de disparo único (One Shot), garantindo que os LEDs desliguem progressivamente após o pressionamento do botão.

---

## 📋 FUNCIONALIDADES
🔹 Acionamento dos LEDs com temporização controlada.  
🔹 Tempo de atraso de 3 segundos entre os estados dos LEDs.  
🔹 Uso da função de callback para alternância dos LEDs.  
🔹 O botão permanece bloqueado até a sequência ser concluída.  
🔹 Debounce por software para evitar leituras erradas.  
🔹 Simulação disponível no Wokwi.  
🔹 Teste físico com LED RGB no BitDogLab (GPIOs 11, 12 e 13).  

---

## 🛠️ PRÉ-REQUISITOS

- 🛠️ HARDWARE NECESSÁRIO:
  
  - Microcontrolador Raspberry Pi Pico W.  
  - 03 LEDs (azul, vermelho e verde). 
  - 03 Resistores de 330 Ω.  
  - 01 Botão (Pushbutton).  
  
- 🖥 SOFTWARE NECESSÁRIO:
  - Raspberry Pi Pico SDK configurado.  
  - CMake para compilação.  
  - VS Code com a extensão Raspberry Pi Pico.  
  - Wokwi para simulação.  

---

## 🔧 REQUISITOS DO PROJETO  
✅ Pressionar o botão liga os três LEDs simultaneamente.  
✅ Cada estado dos LEDs dura 3 segundos antes de alternar.  
✅ Os LEDs desligam progressivamente (3 → 2 → 1 → 0).  
✅ O botão só pode ser pressionado novamente após todos os LEDs apagarem.  
✅ Uso de funções de callback para controle dos LEDs.  
✅ Debounce por software (300 ms) para evitar acionamentos falsos.  

---

## 🚀 COMO EXECUTAR

1️⃣ **Clone este repositório:**

       git clone https://github.com/gustavo-ferreirasantos/EmbarcaTech_OneShot.git

2️⃣ **Abra o VS Code e importe o projeto** 

3️⃣ **Compile o projeto**

4️⃣ **Execute o projeto:**

  - Wokwi para simulação.  
  - Teste físico com BitDogLab (LED RGB nos GPIOs 11, 12 e 13 e botão no GPIO 5).  

---

## 🎥 Vídeo de demonstração
🔗 <u>[Assista aqui](https://youtu.be/feoW6isRvdM)</u>

