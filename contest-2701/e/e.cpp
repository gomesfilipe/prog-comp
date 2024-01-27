#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _data {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
} tdata;

typedef struct _orderData {
    tdata data;
    int diamesano;
    int horaminutosegundo;
    string mensagem = "";
} orderData;

bool cmpData(orderData a, orderData b) 
{
    if (a.diamesano == b.diamesano) {
        return a.horaminutosegundo < b.horaminutosegundo;
    }
    return a.diamesano < b.diamesano;
}

int main()
{
    char linha[100000];
    vector<orderData> mensagens;

    do{
        orderData order;
        if (fgets(linha, 100000, stdin) == NULL)
        {
            break;
        }
        sscanf(linha, "%d/%d/%d %d:%d:%d ", &order.data.dia, &order.data.mes, &order.data.ano, &order.data.hora, &order.data.minuto, &order.data.segundo);
        order.mensagem += (linha + 20);
        order.mensagem.back() = '\0';
        order.diamesano = order.data.dia + order.data.mes * 100 + order.data.ano * 10000;
        order.horaminutosegundo = order.data.hora + order.data.minuto * 100 + order.data.segundo * 10000;
        mensagens.push_back(order);
    } while(true);

    sort(mensagens.begin(), mensagens.end(), cmpData);

    for (int i = 0; i < mensagens.size(); i++) {
        printf("%.2d/%.2d/%.4d %.2d:%.2d:%.2d %s\n", mensagens[i].data.dia, mensagens[i].data.mes, mensagens[i].data.ano, mensagens[i].data.hora, mensagens[i].data.minuto, mensagens[i].data.segundo, mensagens[i].mensagem.c_str());
    }
    
    return 0;
}