//
//  main.cpp
//  Assignment9P1
//
//  Created by GUW06 on 2023-03-15.
//

#include <iostream>
using namespace std;

class Model {
public:
    void setModel(int x) {
        modelData = x;
    }

    int getModel() const {
        return modelData;
    }

private:
    int modelData;
};

class View {
public:
    void printView(int x) {
        cout << "Data: " << x << endl;
    }
};

class Controller {
public:
    Controller(Model& model, View& view) :
    modelData(model), dataView(view) {}

    void setData(int data) {
        modelData.setModel(data);
        dataView.printView(modelData.getModel());
    }

private:
    Model& modelData;
    View&  dataView;
};


