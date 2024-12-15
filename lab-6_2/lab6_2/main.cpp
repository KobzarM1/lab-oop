#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "musicstore.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MusicStore<Instrument> store;
    store.addInstrument(Instrument("Fender Stratocaster", "Guitar", 1500.00));
    store.addInstrument(Instrument("Yamaha P-45", "Keyboard", 499.00));
    store.addInstrument(Instrument("Roland TD-1KV", "Drums", 700.00));
    store.addInstrument(Instrument("Gibson Les Paul", "Guitar", 2500.00));

    QWidget window;
    window.setWindowTitle("Music Store");

    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *label = new QLabel("Welcome to the Music Store!");
    layout->addWidget(label);

    // Можна додати кнопку для виводу інструментів та інших дій
    QPushButton *btnShowInstruments = new QPushButton("Show Instruments");
    layout->addWidget(btnShowInstruments);

    // Прив'язка дій до кнопок

    window.setLayout(layout);
    window.show();

    return app.exec();
}
