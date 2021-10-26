def main():

    lista = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

    testes = int(input())
    numero = ''
    soma = 0

    for c in range(0, testes):

        palavra = input()
        tamanho = len(palavra)
        
        for t in range(0, tamanho):
            try:
                if palavra[t] in lista:
                    numero = numero + palavra[t]
                    
                    if t == tamanho:
                        numero = int(numero)
                        soma = soma + numero
                        print(soma)
                        
                    elif t == tamanho - 1:
                        numero = int(numero)
                        soma = soma + numero
                        print(soma)
                    
                else:
                    if t == tamanho:
                        numero = int(numero)
                        soma = soma + numero
                        print(soma)

                    elif t == tamanho - 1:
                        numero = int(numero)
                        soma = soma + numero
                        print(soma)
                        
                    else:
                        numero = int(numero)
                        soma = soma + numero
                        numero = ''
        
            except ValueError:
                t = t + 1
        
        soma = 0
        numero = ''
                
main()
