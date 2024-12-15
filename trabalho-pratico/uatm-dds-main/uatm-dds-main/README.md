# UATM (Urban Air Traffic Management) - DDS Modeling

Este projeto modela um sistema de Gerenciamento de Tráfego Aéreo Urbano (UATM) usando DDS (Data Distribution Service), com foco na fase **Pre-Departure** de um cenário de voos urbanos.

## Arquitetura

### Domínio
- **UATM_Domain**: Centraliza todos os participantes do sistema.

### Participantes do Domínio
Os principais **Domain Participants** e suas responsabilidades incluem:

1. **anspDP**: Avalia e aprova rotas propostas em colaboração com UASP e USS.
2. **bookingPlatformDP**: Gerencia reservas de voos publicando solicitações de voo.
3. **evtolManagerDP**: Coordena a disponibilidade e alocação de eVTOLs para voos.
4. **fleetOperatorDP**: Supervisiona a logística de voos e atribuições de pilotos e eVTOLs.
5. **flightAuthSysDP**: Processa solicitações e autorizações de voos.
6. **pilotManagerDP**: Gerencia a disponibilidade de pilotos e atualizações de autorizações.
7. **skyportOperatorDP**: Administra serviços e disponibilidade de skyports e fluxo de tráfego.
8. **skyportsManDP**: Supervisiona a alocação de skyports.
9. **tolPadManagerDP**: Gerencia e aloca áreas de decolagem e pouso (TOL Pads).
10. **uaspManagerDP**: Otimiza fluxos de tráfego e gerencia o espaço aéreo urbano.
11. **ussDP**: Identifica rotas aceitáveis para aeronaves não tripuladas.
12. **weatherDP**: Fornece informações meteorológicas essenciais para as operações de voo.

## Tópicos

Os tópicos conectam **DataWriters** e **DataReaders** para troca eficiente de informações:

- **acceptableRoute**: Dados sobre rotas aceitáveis.
- **airspaceRestrictions**: Restrições do espaço aéreo.
- **availabilityInfo**: Informações de disponibilidade de recursos (eVTOLs, pilotos, TOL pads).
- **bookingFlightRequest**: Solicitações de reservas de voos.
- **flightAssign**: Atribuições de voos.
- **flightAuthorization**: Detalhes de autorização de voos.
- **flightCoordination**: Coordenação de voos.
- **weatherInfo**: Condições meteorológicas.

## Políticas de Qualidade de Serviço (QoS)

As políticas QoS garantem comunicação eficiente e confiável:

- **Durability**: Define como os dados persistem (Volatile, Transient Local, Transient, Persistent).
- **Reliability**: Garante entrega confiável dos dados (Reliable, Best Effort).
- **Ownership**: Determina exclusividade ou compartilhamento de dados.
- **Deadline**: Define prazos para entrega de dados.
- **History**: Gerencia armazenamento de amostras (Keep Last, Keep All).

## Visualização e Modelagem

A modelagem foi realizada com o SDK do OpenDDS para representar:

- **Domínio e Participantes**: Organização dos principais componentes.
- **Tópicos e Partições**: Fluxo de dados entre participantes.
- **Diagramas de Pacotes**: Estrutura do sistema.


## Conclusão

O modelo UATM baseado em DDS garante uma infraestrutura robusta e escalável para Gerenciamento de Tráfego Aéreo Urbano, atendendo a requisitos de comunicação, coordenação e segurança.

---

Desenvolvido com base no **OpenDDS** e seguindo padrões de arquitetura orientada a serviços.

