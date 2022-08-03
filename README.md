# Trabalho-1 - Fundamentos de Sistemas Embarcados

Atividade correspondente ao primeiro trabalho da matéria de Fundamentos de Sistemas Embarcados.


## 1. Objetivos

Este trabalho tem por objetivo a criação de um sistema distribuído para o controle e monitoramento de um grupo de sinais de trânsito. O sistema deve ser desenvolvido para funcionar em um conjunto de placas Raspberry Pi com um ***servidor central*** responsável pelo controle e interface com o usuário e ***servidores distribuídos*** para o controle local e monitoramento dos sinais do cruzamento junto aos respectivos sensores que monitoram as vias. Dentre os dispositivos envolvidos estão o controle de temporizaçãio e acionamento dos sinais de trânsito, o acionmento de botões de passagens de pedestres, o monitoramento de sensores de passagem de carros bem como a velocidade da via e o avanço de sinal vermelho.


## 2. Execução do código



1) Acessar a placa raspberry pi desejada:

```sh 
ssh "nome_de_usuario"@"ip_da_placa"
```

2) Clonar o repositório:

```sh 
git clone git@github.com:ilus1/Trabalho-1.git
```

3) Compilar o executável:

```sh 
make all
```

4) Execute a aplicação:

```sh 
./trafficIntersection
```

## Uso 
O projeto foi implementado apenas para o funcionamento dos servidores distribuidos, e até esta etapa o próprio executável deverá se responsabilizar por mapear as GPIOs que serão utilizadas.

