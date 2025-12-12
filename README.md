
# 🐍 Snake Game em C

Este é o clássico **Jogo da Cobrinha (Snake Game)** implementado em **C**, onde você controla uma cobrinha que cresce ao comer itens e precisa evitar colidir com as paredes ou seu próprio corpo.

O objetivo principal deste projeto é praticar lógica de programação em C e aprender conceitos como loops, condicionais, manipulação de arrays e controle de entrada do usuário — típicos em um jogo simples de terminal.

---

## 🎮 Visão Geral

No Snake Game:
- Você guia a cobrinha pelo campo;
- Cada alimento que a cobrinha come faz ela crescer;
- O jogo termina se a cobrinha colidir com as bordas ou com ela mesma.

Este tipo de jogo é muito comum em projetos educativos e ajuda a entender como lidar com dados e entradas interativas no **console**. 

---

## 📁 Conteúdo da Pasta

A pasta `snake game code` deve conter os arquivos fonte do jogo em C:

```

snake game code/
├── main.c
├── snake.c
├── snake.h
└── utils.c

````

> Ajuste conforme os arquivos que você possui nessa pasta.

---

## ⚙️ Requisitos

Antes de compilar e rodar, certifique-se de ter:

- 💻 Sistema com compilador C instalado (como **GCC** ou **Clang**)  
- 📘 Editor ou IDE de sua preferência (VS Code, Code::Blocks, DevC++, etc.)

---

## 📦 Como Compilar e Executar

Abra o terminal/cmd na pasta do projeto e compile com:

```bash
gcc *.c -o snakeGame
````

Ou, se seus arquivos tiverem nomes específicos:

```bash
gcc main.c snake.c utils.c -o snakeGame
```

Após compilar:

```bash
./snakeGame
```

*(No Windows: `snakeGame.exe`)*

---

## ⌨️ Controles

Use o teclado para mover a cobrinha:

* **W** – Cima
* **S** – Baixo
* **A** – Esquerda
* **D** – Direita

*(Ajuste conforme a implementação do seu código caso use outras teclas ou setas)*

---

## 🧠 Como Funciona

O jogo roda no terminal, atualizando o estado da cobrinha em cada iteração.
A lógica principal envolve:

* Atualização da posição da cobra;
* Verificação de colisões;
* Detecção de comida e crescimento;
* Redesenho contínuo do campo.

Projetos similares em C também funcionam como jogos de console sem interface gráfica, o que facilita o aprendizado de programação de baixo nível. 

---

## 📝 Contribuindo

Se quiser colaborar:

1. Faça um fork do repositório;
2. Crie uma branch com sua feature;
3. Envie um pull request com suas mudanças.

---

## 📄 Licença

Este projeto está sob a licença **[MIT License](LICENSE)** — sinta-se livre para usar e adaptar!
*(Coloque a licença real usada se for diferente)*

---

✨ Obrigado por jogar e explorar programação em C! Boa sorte! 🚀
