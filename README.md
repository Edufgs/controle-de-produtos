# controle-de-produtos

Esse é a resolução de uma lista da materia de algoritmos 2, onde é tudo feita na linguagem C

Exercicios: 
1- Faça um programa que simule um controle de estoque de uma loja, onde cada produto, representado por meio de um registro, possui um identificador inteiro, nome, quantidade e custo unitário. O programa deve permitir a inclusão e remoção de novos produtos, consulta de produtos por nome, alteração de registros, geração de relatórios (ex: qual vendeu mais, qual tem maior estoque, produtos cujo estoque estejam abaixo de X unidades, etc.). Todos os registros devem ser armazenados seqüencialmente em um arquivo binário. O programa deve disponibilizar um menu de opções ao usuário. Ex: 1 – Incluir Produto, 2 – consultar, etc.

2- Uma loja de artigos esportivos mantém armazenado no computador do caixa dois arquivos referentes às suas vendas. O primeiro arquivo “CLIENTES.CAD” possui os dados do cliente e o segundo arquivo “VENDAS.CAD” armazena o código e descrição do produto, além do código do cliente que já comprou um item daquele produto. O novo gerente da loja quer saber o que cada cliente tem comprado na loja e para isso solicitou que fosse armazenado em um novo arquivo “COMPRAS.CAD” o nome do cliente e a descrição do produto que ele já adquiriu na loja. 

Escreva um programa que abra os arquivos “CLIENTES.CAD” e “VENDAS.CAD” e construa o novo arquivo “COMPRAS.CAD” utilizando as informações dos dois primeiros arquivos para associar os clientes e suas compras. Ao final, imprima na tela as informações do novo arquivo.

<div align="center">
![image](https://user-images.githubusercontent.com/44234388/138287160-dd11cfc4-cf67-4259-a056-9fd9b2f4f2f3.png)
</div>

3- O arquivo “CONCESSIONÁRIA.CAD” possui um cadastro de todos os veículos disponíveis para venda em uma determinada loja de carros. O proprietário da loja quer atualizar os preços dos veículos com base no ano de fabricação a partir da seguinte regra:

• Carros com menos de um ano de uso 10% de aumento; 
• Carros com menos de três anos de uso e um ano ou mais 7% de aumento; 
• Carros com menos de cinco anos de uso e três anos ou mais 5% de aumento;
• Carros com mais de cinco anos de uso 2% de aumento. 

Escreva um programa que leia este arquivo do disco rígido, atualize o valor do preço de venda do automóvel e salve novamente este arquivo no disco rígido com o nome “CONCESSIONÁRIA_NOVO.CAD”. Para a atualização dos preços deve ser construída uma função AtualizaPreco que receba como entrada o ano de fabricação do carro e seu preço e retorne o novo preço do carro. Durante o processo de atualização dos preços deve ser impressa na tela do computador um relatório com o modelo do carro, seu preço antigo e o novo preço depois da atualização.

OBS.: 
1) Usar como referência o ano de 2011 no cálculo da atualização dos preços; 
2) Utilizar a função AtualizaPreco para calcular os novos os preços dos automóveis.

![image](https://user-images.githubusercontent.com/44234388/138287493-8c533169-1f3a-4ff9-9f26-da139f2d405d.png)

4- Dr. Zinho mantém atualizado no HD de seu computador um arquivo de cadastro de clientes denominado “ZINHO.CAD” e pretende que seja criado um outro arquivo, no mesmo HD com o nome “ZINHO.M50”, correspondente aos dados dos clientes de sexo masculino e que fazem 50 anos em 2011 (nascidos em 1961). Fazer um programa que leia o arquivo “ZINHO.CAD” e crie o arquivo “ZINHO.M50” conforme as estruturas de dados abaixo

![image](https://user-images.githubusercontent.com/44234388/138287570-bc05e511-10cc-4361-be4c-03879cdc21bb.png)
