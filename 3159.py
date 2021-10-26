def main():

    testes = int(input())
    
    digitos = ''
    lista = [['A','B','C','0'],['D','E','F','0'],['G','H','I','0'],['J','K','L','0'],['M','N','O','0'],['P','Q','R','S'],['T','U','V','0'],['W','X','Y','Z']]

    for t in range(0, testes):
        palavra = input()
        comprimento = len(palavra)

        for c in range(0, comprimento):

            for n in range(0, 8):

                for l in range(0, 4):

                    if palavra[c].upper() == lista[n][l]:
                        botao = lista[n]
                        
                        #Descobrir qual a posição está na lista e multiplicar a posição para imprimir a quantidade de números correspondentes (ex: c -> 222)
                        if (palavra[c] == botao[0].upper()) or (palavra[c] == botao[1].upper()) or (palavra[c] == botao[2].upper()) or (palavra[c] == botao[3].upper()):
                            digitos = digitos + "#" + (str(n + 2) * (l + 1))
                            
                        else:
                            #Ver se a letra anterior e a atual estão na mesma lista
                            if palavra[c-1].upper() in lista[n] and palavra[c].upper() in lista[n] and c != 0:
                                digitos = digitos + "*" + (str(n + 2) * (l + 1))

                            else:
                                digitos = digitos + str(n + 2) * (l + 1)

            if palavra[c] == ' ':
                digitos = digitos + '0'

        print(digitos)
        digitos = ''

main()
