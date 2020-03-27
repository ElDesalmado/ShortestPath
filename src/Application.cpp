#include "qapplication.h"

#include "AppDialog.h"

int main(int argc, char **argv)
{
    QApplication app{ argc, argv };
    AppDialog dialog;
    dialog.show();

    return app.exec();
}
