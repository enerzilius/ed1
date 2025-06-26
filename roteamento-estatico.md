# configurar um roteador CISCO
- Um roteador pode ser qualquer computador
- Mas existem especializados
  - *mais consistente, menos sucetível à falha e mais seguro*
  - Ligar o cabo serial em um computador e fazer a configuração
    - No GNS3 é só fazer 2 clicks
```bash
R-CISCO> enable
(?senha)
R-CISCO#
```
Pegar Permissão de admin (no GNS3 não precisa)

```bash
R-CISCO# show ? // mostra os comandos
R-CISCO# show ip interface  brief // conexões da placa de rede
R-CISCO# show ip route // mostra as conexões IP
```

- ### Atribuir IP na placa de rede
```bash
R-CISCO#configure terminal // entra no nível de configuração
R-CISCO(config)#interface f0/0 // selecionar a interface
R-CISCO(config-if)#ip address 10.1.0.100 255.255.255.0 // aqui PRECIS escrever a máscara inteira
R-CISCO(config-if)#no shutdown // o no cancela algum comando
R-CISCO(config-if)#exit // volta um nível
R-CISCO(config)#end // volta pro início
R-CISCO#ping 10.1.0.1 // ! é sucesso e . é falha
Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 10.1.0.1, timeout is 2 seconds:
.!!!!
Success rate is 80 percent (4/5), round-trip min/avg/max = 4/8/12 ms

```

```bash
R-CISCO#show run // show running-config, mostra as alterações já feitas na rede
R-CISCO#copy running-config startup-config // garante que as alterações sejam salvas mesmo depois de desligado
```

```bash
R-CISCO#ip route 10.1.0.0 255.255.255.0 172.30.1.100 // adiciona à tabela de roteamento uma rede não ligada diretamente 
    // adiciona a conexão à 10.1.0.0 pela rede 172.30.1.100
    // ^- isso é um rota estática!
```