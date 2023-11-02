#include "minisupermarketmanagement.h"
#include "./ui_minisupermarketmanagement.h"
#include "managerproduct.h"// ui
#include "managerproduct.h" // Thêm tệp phụ thuộc cho cửa sổ manager produc

using namespace std ;
static bool hasReadFile = false; // Biến tĩnh (static) sẽ chỉ được khởi tạo một lần và giữ giá trị qua các lần gọi hàm



MiniSupermarKetmanagement::MiniSupermarKetmanagement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MiniSupermarKetmanagement)
{
    ui->setupUi(this);

}

MiniSupermarKetmanagement::~MiniSupermarKetmanagement()
{
    delete ui;
}

void MiniSupermarKetmanagement::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}


void MiniSupermarKetmanagement::on_pushButton_clicked()
{
    if (!hasReadFile) {
        ManagerProduct manager(this, hasReadFile);
        manager.setModal(true);
        manager.exec();

        // Đánh dấu rằng đã mở form và đọc file
        hasReadFile = true;
    }
    else {
        ManagerProduct manager(this, hasReadFile);
        manager.setModal(true);
        manager.exec();
        // Form đã mở và đã đọc file, không cần làm gì nữa
    }
}

