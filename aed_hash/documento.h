#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <QStringList>
#include <fstream>
#include <list>


class documento
{
public:
    documento(std::string arquivo);
    int getP_dist();
    QStringList* getPalavras();
    std::string getDoc() const;

private:
    QStringList *setPalavras();
    std::string doc;
    int p_dist;
    QStringList palavras;
};

#endif // DOCUMENTO_H
