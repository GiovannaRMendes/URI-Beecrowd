def main():

    #Leia o dia e o horário que o evento vai iniciar
    palavra1, dia1 = input().split()
    hora1, minuto1, segundo1 = map(int, input().split(':'))
    dia1 = int(dia1)
    
    #Leia o dia e o horário que o evento vai terminar
    palavra2, dia2 = input().split()
    hora2, minuto2, segundo2 = map(int, input().split(':'))
    dia2 = int(dia2)

    #Transforme tudo em segundos
    total_segundos1 = segundo1 + (minuto1 * 60) + (hora1 * 3600) + (dia1 * 86400)
    total_segundos2 = segundo2 + (minuto2 * 60) + (hora2 * 3600) + (dia2 * 86400)
    total_segundos = abs(total_segundos2 - total_segundos1)
    
    #Descubra quantos dias duram o evento
    total_dias = total_segundos//86400
    total_segundos = total_segundos%86400
    
    #Descubra quantas horas duram o evento
    total_horas = total_segundos//3600
    total_segundos = total_segundos%3600

    #Descubra quantos minutos duram o evento
    total_minutos = total_segundos//60
    
    #Descubra quantos segundos duram o evento
    total_segundos = total_segundos % 60

    #Imprima os valores
    print('{} dia(s)'.format(total_dias))
    print('{} hora(s)'.format(total_horas))
    print('{} minuto(s)'.format(total_minutos))
    print('{} segundo(s)'.format(total_segundos))
    
main()
