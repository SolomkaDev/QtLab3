#ifndef SAVEDATAH_H
#define SAVEDATAH_H
#include "Camera_Catalogy.h"

class Base {
public:
    QString modul;
    int category_value;
    int producer_value;
    double matrix_px;
    QString dimension;
    int weight;
    int price;
    QDate date_release;
    bool IsDigital;
    bool LensOption;
    
    //Первый вариант перегрузки
    /*
    bool operator>(Base other) {
        
        if (category_value > other.category_value)
            return true;
        else {
            if (category_value == other.category_value) {
                if (matrix_px > other.matrix_px)
                    return true;
                else {
                    if (matrix_px == other.matrix_px) {
                        if (price > other.price)
                            return true;
                        else {
                            if (price == other.price) {
                                if (producer_value > other.producer_value)
                                    return true;
                                else {
                                    if (producer_value == other.producer_value) {
                                        if (modul > other.modul)
                                            return true;
                                        else return false; //modul
                                    }
                                    else return false; //producer_value
                                }
                            }
                            else return false; //price
                        }
                    }
                    else return false; //matrix_px
                }
            }
            else return false; //category_value
        }

    }
    */
    
    //Третий вариант перегрузки

    bool operator>(Base other) {
        if (category_value > other.category_value) {
            return true;
        }
        else if (category_value == other.category_value) {
            if (IsDigital) {
                if (matrix_px > other.matrix_px)
                    return true;
                else if (matrix_px == other.matrix_px) {
                    if (price > other.price)
                        return true;
                    else if (price == other.price) {
                        if (producer_value > other.producer_value)
                            return true;
                        else if (producer_value == other.producer_value) {
                            if (modul > other.modul)
                                return true;
                            else return false; //modul 1
                        }
                        else return false; //produce_value 1
                    }
                    else return false; //price 1
                }
                else return false; //matrix_px
            }
            else {
                if (price > other.price)
                    return true;
                else if (price == other.price) {
                    if (producer_value > other.producer_value)
                        return true;
                    else if (producer_value == other.producer_value) {
                        if (modul > other.modul)
                            return true;
                        else return false; //modul 2
                    }
                    else return false; //produce_value 2
                }
                else return false; //price 2
            }
        }
        else return false; //category_value
    }

    //Второй вариант перегрузки
    
    /*
    bool operator>(Base other) {
        if (category_value > other.category_value) {
            return true;
        }
        else if (category_value < other.category_value) {
            return false;
        }

        if (IsDigital && other.IsDigital) {
            if (price > other.price) {
                return true;
            }
            else if (price < other.price) {
                return false;
            }
        }
        else {
            if (matrix_px > other.matrix_px) {
                return true;
            }
            else if (matrix_px < other.matrix_px) {
                return false;
            }
        }

        if (price > other.price) {
            return true;
        }
        else if (price < other.price) {
            return false;
        }

        if (producer_value > other.producer_value) {
            return true;
        }
        else if (producer_value < other.producer_value) {
            return false;
        }

        return modul > other.modul;
    }
    */

    bool operator==(Base other) {
        if (modul == other.modul) {
            if (category_value == other.category_value) {
                if (producer_value == other.producer_value) {
                    if (matrix_px == other.matrix_px) {
                        if (dimension == other.dimension) {
                            if (weight == other.weight) {
                                if (price == other.price) {
                                    if (date_release == other.date_release) {
                                        if (IsDigital == other.IsDigital) {
                                            if (LensOption == other.LensOption) {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    
    Base() {
        modul = "";
        category_value = 0;
        producer_value = 0;
        matrix_px = 2;
        dimension = "00-00-00";
        weight = 100;
        price = 1000;
        date_release = QDate::currentDate();
        IsDigital = false;
        LensOption = false;
    }
    
};


#endif // SAVEDATAH_H