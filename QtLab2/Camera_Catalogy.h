#pragma once

//#define CAMERACATALOGY_H
//#ifndef CAMERACATALOGY_H


#include <QtWidgets/QMainWindow>
#include "ui_Camera_Catalogy.h"
#include <QMainWindow>
#include "SaveDatah.h"
#include <QtCore>
#include <QVector>
#include <QDebug>
//#include "Info_Storage.h"

//���� �� 2 ����
/*
class Storage_Camera {
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
        Storage_Camera() {
            modul = "";
            category_value = 0;
            producer_value = 0;
            matrix_px = 2;
            dimension = "00-00-00";
            weight = 100;
            price = 10000;
            date_release = QDate::currentDate();
            IsDigital = false;
            LensOption = false;
        }
};
*/

class Camera_Catalogy : public QMainWindow
{
    Q_OBJECT

public:
    Camera_Catalogy(QWidget *parent = Q_NULLPTR);
    //Base Items[2];
    
    //������� ������ ��������
    QVector <Base> Items;
    int sizeVector = 0;
    
    void Sort()
    {
        for (int i = 0; i < Items.count(); i++) {
            for (int j = 0; j < Items.count() - 1; j++) {
                if (Items[j] > Items[j + 1]) {
                    Base b = Items[j]; // ������� �������������� ����������
                    Items[j] = Items[j + 1]; // ������ �������
                    Items[j + 1] = b; // �������� ���������
                }
            }
        }

    }
    //Storage_Camera* Items = new Storage_Camera[2];

    /*
    int Data_arr_size = 2; //������ ������� �� ���������

    //������� ��� ��������������� �������(����� ��� �������� ��������)
    void Data_Reverse(Storage_Camera* Current_Arr, int Data_arr_size) {
        Storage_Camera* x = new Storage_Camera[Data_arr_size];

        for (int i = 0; i < (Data_arr_size/2); i++) {
            x[i] = Current_Arr[i];
            Current_Arr[i] = Current_Arr[Data_arr_size - i - 1];
            Current_Arr[Data_arr_size - i - 1] = x[i];
        }
        delete[]x;
    }
    */
    

private:
    Ui::Camera_CatalogyClass ui;
    private slots:
        //������ �� 2 ����
        /*
        void slot_save1(); //���������|������������ ������ ������
        void slot_save2(); //���������|������������ ������ ������
        void slot_show1(); //�������� ������ ������ ������
        void slot_show2(); //�������� ������ ������ ������
        */
        void slot_LensOptions(); //������� � ������������ ����� ���������
        void slot_IsDigital(); //������� �������� �� ������ ��������
        void slot_ChooseCategory(); //����� ��������� ������ �� ����������� ������
        void slot_ChooseProducer(); //����� ������������� ������ �� ����������� ������
        //������ ��������������
        void slot_Add_data();
        void slot_Add_data10();
        void slot_Save_data();
        void slot_Delete_data();

        //���� ��� ��������
        void slot_TableInfo();

        
};

//#endif // CAMERACATALOGY_H