#include <iostream>
#include <stdlib.h>

//встроенный кассовый аппарат
class cashRegister {
private:
    int cashOnHand;

public:
    //определяем количество денег в кассе равным 500
    cashRegister() {
        cashOnHand = 500;
    }

    //определяет количество наличных в кассе на определенную сумму
    cashRegister(int cash) {
        cashOnHand = cash;
    }

    //возвращает значение cashOnHand
    int getCurrentBalance() {
        return cashOnHand;
    }
    //внесение суммы клиентом и обновление суммы в кассе
    void acceptAmount(int cashDeposited) {
        cashOnHand += cashDeposited;
    }
};

//раздатчик
class dispenserType {
private:
    int numberOfItems;
    int TypeCost;

public:
    //устанавливает стоимость и количество предметов в диспенсере по 50 штук
    dispenserType() {
        numberOfItems = 50;
        TypeCost = rand() % 15 + 5;
    }

    //устанавливает стоимость и количество предметов в диспенсере на значения, указанные пользователем
    dispenserType(int setCost, int setAmount) {
        TypeCost = setCost;
        numberOfItems = setAmount;
    }

    //для возврата значения NumberOfItems
    int getNoOfitems() {
        return numberOfItems;
    }

    // для возврата значения стоимости
    int getCost() {
        return TypeCost;
    }

    //для уменьшения количества товаров на 1 единицу
    void makeSale() {
        numberOfItems -= 1;
    }

};

void showSelection() {
    std::cout << "---------" << std::endl;
    std::cout << "Benvenuti! This candy machine sells four different items: sweets, chips, chewing-gun and biscuits." << std::endl;
    std::cout << "Every item has a special code. To make a purchase insert the code of the item." << std::endl;
    std::cout << "1. Sweets\n2. Chips\n3. Chewing-gum\n4. Biscuits" << std::endl;
    std::cout << "If you want to exit insert 0." << std::endl;
}

void sellProduct(dispenserType& prodotto, cashRegister& qualcosa) {
    int moneyDeposited;  //внесенные деньги
    int extraNeeded;  //значение денег, которых не хватает
    int extraInserted;  //лишние деньги
    int prezzo = prodotto.getCost(); //цена
    int choiceDue; //возможность доплатить или выйти

    //проверяем доступность продукта
    if (prodotto.getNoOfitems() != 0) {
        //показывает стоимость
        std::cout << "This product costs " << prezzo << "$." << std::endl;
        //внесение денег
        std::cout << "Insert the money: ";
        std::cin >> moneyDeposited;

        //внесена полная сумма товара
        if (moneyDeposited == prezzo) {
            qualcosa.acceptAmount(moneyDeposited);
            prodotto.makeSale();
            std::cout << "Congratulations on your purchase! We are hoping to see you again soon!" << std::endl;
        }
        //внесена сумма превышающая цену товара
        else if (moneyDeposited > prezzo) {
            extraInserted = moneyDeposited - prezzo;
            moneyDeposited -= extraInserted;
            qualcosa.acceptAmount(moneyDeposited);
            prodotto.makeSale();
            std::cout << "You've inserted extra " << extraInserted << "$. ";
            std::cout << "Don't forget to collect them back along with the product!" << std::endl;
            std::cout << "Congratulations on your purchase! We are hoping to see you again soon!" << std::endl;
        }
        //внесена неполная сумма товара
        else if (moneyDeposited < prezzo) {
            extraNeeded = prezzo - moneyDeposited;
            std::cout << "ERROR! Deposit another " << extraNeeded << "$." << std::endl;
            std::cout << "Insert 1 if you want to deposit another " << extraNeeded << "$." << std::endl;
            std::cout << "Insert 0 if you want to cancel purchase and exit." << std::endl;
            std::cin >> choiceDue;

            if (choiceDue == 1) {
                moneyDeposited += extraNeeded;
                qualcosa.acceptAmount(moneyDeposited);
                prodotto.makeSale();
                std::cout << "Congratulations on your purchase! We are hoping to see you again soon!" << std::endl;
            }
            else if (choiceDue == 0) {
                std::cout << "You've exited." << std::endl;
            }
        }
    }
    else {
        std::cout << "This item is sold and no longer available. " << std::endl;
    }
}

int main()
{
    dispenserType Dolci(10, 50); //конфеты
    dispenserType PatatineFritte(13, 50);  //чипсы
    dispenserType Mentine(5, 50); //жвачка
    dispenserType Biscotti(11, 50);  //печенье
    cashRegister Reg;

    int choice; //переменная для выбора
    showSelection();
    std::cin >> choice;

    while (choice != 0) {
        switch (choice) {
            //покупаем конфеты
        case 1:
            sellProduct(Dolci, Reg);
            break;
            //покупаем чипсы
        case 2:
            sellProduct(PatatineFritte, Reg);
            break;
            //покупаем жвачку
        case 3:
            sellProduct(Mentine, Reg);
            break;
            //покупаем печенье
        case 4:
            sellProduct(Biscotti, Reg);
            break;
        }

        showSelection();
        std::cin >> choice;
    }
    return 0;
}