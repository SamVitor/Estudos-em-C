#include <stdio.h>

int main(){
//Carta 1
    char estado1[3], codigo_da_cidade1[4], nome_da_cidade1[60];
    int pontos_turisticos1;
    unsigned long int pop1;
    float Km2_1, PIB1, DensPop1, PIBperCapt1, inv_denspop1, super_poder1;
 
//entrada das variaveis
    printf("Escolha a primeira carta para digitalizar\nAgora siga as instruções\n");
    
    printf("Digite a inicial estado: \n");
    scanf("%s", &estado1);

    printf("Digite o codigo da cidade, \n");
    scanf("%s", codigo_da_cidade1);

    printf("Digite o nome da cidade: \n");
    scanf("%s", nome_da_cidade1);

    printf("Digite o numero populacional da cidade: \n");
    scanf("%lu", &pop1);

    printf("Digite o numero de pontos turisticos da cidade: \n");
    scanf("%d", &pontos_turisticos1);

    printf("Digite, em Km², o tamanho territorial da cidade: \n");
    scanf("%f", &Km2_1);
    
    printf("Qual o Produto Interno Bruto desta cidade: \n");
    scanf("%f", &PIB1);

//Calculos

    DensPop1 = (pop1 / Km2_1);
    PIBperCapt1 = (PIB1 / pop1);
    inv_denspop1 = 1.0f / DensPop1;
    
    super_poder1 = pop1 + Km2_1 + PIB1 + (float)pontos_turisticos1 + PIBperCapt1 + inv_denspop1;


//Exibição final carta 1
    printf("Verificação de dados, Carta 1: \n");

    printf("Estado: %s \n", &estado1);

    printf("Código: %s \n", codigo_da_cidade1);

    printf("Nome da cidade: %s \n", nome_da_cidade1);

    printf("População: %lu \n", pop1);

    printf("Área em Km²: %.3f \n", Km2_1);

    printf("O Produto Interno Bruto é de: %.2f \n", PIB1);

    printf("Número de pontos turísticos: %d \n", pontos_turisticos1);

    printf("Densidade Populacional: %.3f \n", DensPop1);

    printf("PIB per Capita: %.2f \n", PIBperCapt1);

    printf("Seu super poder é de: %.3f \n", super_poder1);

    
//Carta 2
    char estado2[3], codigo_da_cidade2[4], nome_da_cidade2[60];
    int pontos_turisticos2;
    unsigned long int pop2;
    float Km2_2, PIB2, DensPop2, PIBperCapt2, inv_denspop2, super_poder2;

//entrada das variaveis
    printf("Escolha a segunda carta para digitalizar\nAgora siga as instruções\n");
    
    printf("Digite a inicial estado: \n");
    scanf("%s", &estado2);

    printf("Digite o codigo da cidade, \n");
    scanf("%s", codigo_da_cidade2);

    printf("Digite o nome da cidade: \n");
    scanf("%s", nome_da_cidade2);

    printf("Digite o numero populacional da cidade: \n");
    scanf("%lu", &pop2);

    printf("Digite o numero de pontos turisticos da cidade: \n");
    scanf("%d", &pontos_turisticos2);

    printf("Digite, em Km², o tamanho territorial da cidade: \n");
    scanf("%f", &Km2_2);
    
    printf("Qual o Produto Interno Bruto desta cidade: \n");
    scanf("%f", &PIB2);

//Calculos

    DensPop2 = (pop2 / Km2_2);
    PIBperCapt2 = (PIB2 / pop2);
    inv_denspop2 = 1.0f / DensPop2;
    
    super_poder2 = pop2 + Km2_2 + PIB2 + (float)pontos_turisticos2 + PIBperCapt2 + inv_denspop2;

//Exibição final carta 2
    printf("Verificação de dados, Carta 2: \n");

    printf("Estado: %s \n", &estado2);

    printf("Código: %s \n", codigo_da_cidade2);

    printf("Nome da cidade: %s \n", nome_da_cidade2);

    printf("População: %lu \n", pop2);

    printf("Área em Km²: %.3f \n", Km2_2);

    printf("O Produto Interno Bruto é de: %.2f \n", PIB2);

    printf("Número de pontos turísticos: %d \n", pontos_turisticos2);

    printf("Densidade Populacional: %.3f \n", DensPop2);

    printf("PIB per Capita: %.2f \n", PIBperCapt2);

    printf("Seu super poder é de: %.3f \n", super_poder2);

    
//camparação das cartas

//variaveis de resultado
/*    int resultadoPT, resultadopop, resultadokm2, resultadopib, resultadopercapt, resultadoDenspop, resultadopoder;

    printf("Comparação das cartas\n");
    printf("Valor = 1 Vitoria da carta 1, Valor = 0 Vitoria da carta 2\n");

    resultadoPT = pontos_turisticos1 > pontos_turisticos2;
    printf("Pontos turisticos, vitoria:%d\n", resultadoPT);

    resultadopop = pop1 > pop2;
    printf("Numero populacional, Win:%d\n", resultadopop);

    resultadokm2 = Km2_1 > Km2_2;
    printf("Kilometros quadrados, Win:%d\n", resultadokm2);

    resultadopib = PIB1 > PIB2;
    printf("Produto interno bruto, Win:%d\n", resultadopib);

    resultadoDenspop = DensPop1 < DensPop2;
    printf("Densidade populacional, Win:%d\n", resultadoDenspop);

    resultadopercapt = PIBperCapt1 > PIBperCapt2;
    printf("Renda per Capta, Win:%d\n", resultadopercapt);

    resultadopoder= super_poder1 > super_poder2;
    printf("Nivel de poder, Win:%d\n", resultadopoder);

//comparação das cartas if-else
    if (pontos_turisticos1 > pontos_turisticos2){
        printf("Carta numero 1 tem maior numero de pontos turisticos\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem maior numero de pontos turisticos\n");
        printf("Vencedor! %s\n", &estado2);
    }
    
    if (pop1 > pop2){
        printf("Carta numero 1 tem um maior numero populacional\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem um maior numero populacional\n");
        printf("Vencedor!%s \n", &estado2);
    }

    if (Km2_1 > Km2_2){
        printf("Carta numero 1 tem um maior territorio em km2\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem um maior territorio em km2\n");
        printf("Vencedor! %s\n", &estado2);
    }

    if (PIB1 > PIB2){
        printf("Carta numero 1 tem maior PIB\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem maior PIB\n");
        printf("Vencedor!%s \n", &estado2);
    }

    if (DensPop1 < DensPop2){
        printf("Carta numero 1 tem menor densidade populacional\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem menor densidade populacional\n");
        printf("Vencedor!%s \n", &estado2);
    }

    if (PIBperCapt1 > PIBperCapt2){
        printf("Carta numero 1 tem o produto interno por habitante maior\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem o produto interno por habitante maior\n");
        printf("Vencedor!%s \n", &estado2);
    }

    if (super_poder1 > super_poder2){
        printf("Carta numero 1 tem poder maior\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem poder maior\n");
        printf("Vencedor!%s \n", &estado2);
    }

    
*/
//Escolhendo atributo a ser comparado

    printf("Escolha um atributo para comparar entre as cartas: \n");

    int opcao;

    printf("Escolha uma opção:\n");
    printf("1. Estado\n");
    printf("2. população\n");
    printf("3. Area\n");
    printf("4. PIB\n");
    printf("5. Numero de pontos turisticos\n");
    printf("6. Densidade demografica\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Os estados escolhidos são: %s e %s \n", estado1, estado2);
        break;
    case 2:
         if (pop1 > pop2){
        printf("Carta numero 1 tem um maior numero populacional\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem um maior numero populacional\n");
        printf("Vencedor!%s \n", &estado2);
    }
        break;
    case 3:
           if (Km2_1 > Km2_2){
        printf("Carta numero 1 tem um maior territorio em km2\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem um maior territorio em km2\n");
        printf("Vencedor! %s\n", &estado2);
    }
        break;
    case 4:
        if (PIBperCapt1 > PIBperCapt2){
        printf("Carta numero 1 tem o produto interno por habitante maior\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem o produto interno por habitante maior\n");
        printf("Vencedor!%s \n", &estado2);
    }
    case 5:
        if (pontos_turisticos1 > pontos_turisticos2){
        printf("Carta numero 1 tem maior numero de pontos turisticos\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem maior numero de pontos turisticos\n");
        printf("Vencedor! %s\n", &estado2);
    }
    case 6:
        if (DensPop1 < DensPop2){
        printf("Carta numero 1 tem menor densidade populacional\n");
        printf("Vencedor! %s\n", &estado1);
    }else{
        printf("Carta numero 2 tem menor densidade populacional\n");
        printf("Vencedor!%s \n", &estado2);
    }    

    default:
    printf("Opção invalida\n");
    printf("inicie novamente\n");

        return 0;


}}
