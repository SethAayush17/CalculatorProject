#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <cmath>
#include <QString>
#include <vector>
#include <QJSEngine>
#include <sstream>
#include <iomanip>

/**
 * @brief Split1 - Splits a QString containing a mathematical expression into tokens
 * @param input - The expression string to split
 * @return A vector of QString tokens (numbers and operators)
 */
std::vector<QString> Split1(QString input) {
    std::vector<QString> vector;
    QString string = "";
    string += input[0];

    // Handle single character input
    if (input.length() == 1) {
        vector.push_back(string);
    }

    // Process the rest of the input character by character
    for (int i = 1; i < input.size();) {
        // Handle the last character
        if (i == int(input.size()) - 1) {
            if (input[i] == '+' || input[i] == '-' || input[i] == 'X' || input[i] == char(0x00F7)) {
                vector.push_back(string);
                string = "";
                string += input[i];
                vector.push_back(string);
                break;
            } else {
                string += input[i];
                vector.push_back(string);
                break;
            }
        }

        // Handle operators in the middle of the expression
        if (input[i] == '+' || input[i] == '-' || input[i] == 'X' || input[i] == char(0x00F7)) {
            vector.push_back(string);
            string = "";
            string += input[i];
            vector.push_back(string);
            string = "";
            string += input[i+1];

            if (i + 1 == int(input.size()) - 1) {
                vector.push_back(string);
                break;
            } else {
                i = i + 2;
            }
        } else {
            string += input[i];
            ++i;
        }
    }

    return vector;
}

/**
 * @brief MainWindow::ChangeHistory - Updates the calculation history in the UI
 * @param history2 - The new history entry to add
 */
void MainWindow::ChangeHistory(QString history2) {
    // Get all line edits in the history widget
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();

    // Shift all entries down one position
    for (int i = int(lineedits.size()) - 1; i >= 0; --i) {
        if (i == int(lineedits.size()) - 1) {
            lineedits[i]->clear();
        } else if (i == 0) {
            if (lineedits[i]->text().isEmpty()) {
                lineedits[i]->setText(history2);
            } else {
                QString moving = lineedits[i]->text();
                lineedits[i+1]->setText(moving);
                lineedits[i]->setText(history2);
            }
        } else {
            QString moving = lineedits[i]->text();
            lineedits[i+1]->setText(moving);
        }
    }
}

/**
 * @brief MainWindow::MainWindow - Constructor for the calculator window
 * @param parent - Parent widget
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set right alignment for the output display
    ui->output->setAlignment(Qt::AlignRight);

    // Fix the window size
    this->setFixedSize(885, 550);
}

/**
 * @brief MainWindow::~MainWindow - Destructor for the calculator window
 */
MainWindow::~MainWindow()
{
    delete ui;
}

// =============================================
// NUMBER BUTTON HANDLERS
// =============================================

/**
 * @brief MainWindow::on_BTN0_clicked - Handler for the '0' button
 */
void MainWindow::on_BTN0_clicked()
{
    bool condition = true;
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    string1 = ui->output->text();

    // Prevent multiple leading zeros
    if (!string1.isEmpty()) {
        if (string1[0] == '0' && string1.size() == 1) {
            condition = false;
        }
    }

    if (condition) {
        ui->output->insert("0");
    }
}

/**
 * @brief MainWindow::on_BTN1_clicked - Handler for the '1' button
 */
void MainWindow::on_BTN1_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("1");
}

/**
 * @brief MainWindow::on_BTN2_clicked - Handler for the '2' button
 */
void MainWindow::on_BTN2_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("2");
}

/**
 * @brief MainWindow::on_BTN3_clicked - Handler for the '3' button
 */
void MainWindow::on_BTN3_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("3");
}

/**
 * @brief MainWindow::on_BTN4_clicked - Handler for the '4' button
 */
void MainWindow::on_BTN4_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("4");
}

/**
 * @brief MainWindow::on_BTN5_clicked - Handler for the '5' button
 */
void MainWindow::on_BTN5_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("5");
}

/**
 * @brief MainWindow::on_BTN6_clicked - Handler for the '6' button
 */
void MainWindow::on_BTN6_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("6");
}

/**
 * @brief MainWindow::on_BTN7_clicked - Handler for the '7' button
 */
void MainWindow::on_BTN7_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("7");
}

/**
 * @brief MainWindow::on_BTN8_clicked - Handler for the '8' button
 */
void MainWindow::on_BTN8_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("8");
}

/**
 * @brief MainWindow::on_BTN9_clicked - Handler for the '9' button
 */
void MainWindow::on_BTN9_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    ui->output->insert("9");
}

// =============================================
// OPERATOR BUTTON HANDLERS
// =============================================

/**
 * @brief MainWindow::on_BTNAdd_clicked - Handler for the '+' button
 */
void MainWindow::on_BTNAdd_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    bool contains = false;
    QString text = ui->output->text();

    // Check if expression already contains an operator
    if (!text.isEmpty()) {
        for (int i = 1; i < text.length(); ++i) {
            if (text[i] == '+' || text[i] == '-' || text[i] == 'X' || text[i] == char(0x00F7)) {
                contains = true;
            }
        }
    }

    // If there's already an operator, evaluate first, then add +
    if (contains == true) {
        if (text[text.length() - 1] != '+') {
            ui->BTNEqual->click();
            ui->output->insert("+");
        }
    } else {
        ui->output->insert("+");
    }
}

/**
 * @brief MainWindow::on_BTNSub_clicked - Handler for the '-' button
 */
void MainWindow::on_BTNSub_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    bool contains = false;
    QString text = ui->output->text();

    // Check if expression already contains an operator
    if (!text.isEmpty()) {
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == '+' || text[i] == '-' || text[i] == 'X' || text[i] == char(0x00F7)) {
                contains = true;
            }
        }
    }

    // If there's already an operator, evaluate first, then add -
    if (contains == true) {
        if (text[text.length() - 1] != '-') {
            ui->BTNEqual->click();
            ui->output->insert("-");
        }
    } else {
        ui->output->insert("-");
    }
}

/**
 * @brief MainWindow::on_BTNMultiply_clicked - Handler for the 'X' button
 */
void MainWindow::on_BTNMultiply_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    bool contains = false;
    QString text = ui->output->text();

    // Check if expression already contains an operator
    if (!text.isEmpty()) {
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == '+' || text[i] == '-' || text[i] == 'X' || text[i] == char(0x00F7)) {
                contains = true;
            }
        }
    }

    // If there's already an operator, evaluate first, then add X
    if (contains == true) {
        if (text[text.length() - 1] != 'X') {
            ui->BTNEqual->click();
            ui->output->insert("X");
        }
    } else {
        ui->output->insert("X");
    }
}

/**
 * @brief MainWindow::on_BTNDivide_clicked - Handler for the '÷' button
 */
void MainWindow::on_BTNDivide_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    bool contains = false;
    QString text = ui->output->text();

    // Check if expression already contains an operator
    if (!text.isEmpty()) {
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == '+' || text[i] == '-' || text[i] == 'X' || text[i] == char(0x00F7)) {
                contains = true;
            }
        }
    }

    // If there's already an operator, evaluate first, then add ÷
    if (contains == true) {
        if (text[text.length() - 1] != '+') {
            ui->BTNEqual->click();
            ui->output->insert("÷");
        }
    } else {
        ui->output->insert("÷");
    }
}

/**
 * @brief MainWindow::on_BTNEqual_clicked - Handler for the '=' button
 */
void MainWindow::on_BTNEqual_clicked()
{
    QString string2 = ui->output->text();

    // Clear error messages if present
    if (string2 == "Number too small!" || string2 == "Number too big!") {
        ui->output->clear();
    }

    QString string1 = ui->output->text();
    QString history2 = string1;
    history2 += '=';

    // Only perform calculation if the last character is not an operator
    if (string1[string1.length() - 1] != '+' &&
        string1[string1.length() - 1] != '-' &&
        string1[string1.length() - 1] != 'X' &&
        string1[string1.length() - 1] != char(0x00F7)) {

        // Convert operators to JavaScript compatible format
        for (int i = 0; i < string1.length(); ++i) {
            if (string1[i] == 'X') {
                string1[i] = '*';
            }
            if (string1[i] == char(0x00F7)) {
                string1[i] = '/';
            }
        }

        // Evaluate the expression using JavaScript engine
        QJSEngine engine;
        QJSValue result = engine.evaluate(string1);
        QString output = result.toString();
        ui->output->setText(output);
        history2 += output;

        // Update calculation history
        ChangeHistory(history2);
    }
}

// =============================================
// UTILITY BUTTON HANDLERS
// =============================================

/**
 * @brief MainWindow::on_BTNbackspace_clicked - Handler for the backspace button
 */
void MainWindow::on_BTNbackspace_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    // Remove last character from the display
    QString text = ui->output->text();
    text.chop(1);
    ui->output->setText(text);
}

/**
 * @brief MainWindow::on_BTNDecimal_clicked - Handler for the decimal point button
 */
void MainWindow::on_BTNDecimal_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    QString text = ui->output->text();
    bool condition = false;

    // Check if current number already contains a decimal point
    if (!text.isEmpty()) {
        std::vector<QString> vector = Split1(text);
        for (int i = 0; i < vector[int(vector.size()) - 1].length(); ++i) {
            if (vector[int(vector.size()) - 1][i] == '.') {
                condition = true;
            }
        }
    }

    // Insert decimal point if one doesn't exist yet
    if (condition == false && !text.isEmpty()) {
        ui->output->insert(".");
    }
}

/**
 * @brief MainWindow::on_BTNClear_clicked - Handler for the Clear button
 */
void MainWindow::on_BTNClear_clicked()
{
    ui->output->clear();
}

/**
 * @brief MainWindow::on_BTNEntryClear_clicked - Handler for the Clear Entry button
 */
void MainWindow::on_BTNEntryClear_clicked()
{
    QString text = ui->output->text();

    if (!text.isEmpty()) {
        // Split the expression and remove the last number entry
        std::vector<QString> vector = Split1(text);

        if (vector[int(vector.size()) - 1] != '+' &&
            vector[int(vector.size()) - 1] != '-' &&
            vector[int(vector.size()) - 1] != 'X' &&
            vector[int(vector.size()) - 1] != char(0x00F7)) {
            vector.pop_back();
        }

        // Reconstruct the text without the last entry
        QString new_text;
        for (int i = 0; i < vector.size(); ++i) {
            new_text += vector[i];
        }

        ui->output->setText(new_text);
    }
}

// =============================================
// MATHEMATICAL FUNCTION HANDLERS
// =============================================

/**
 * @brief MainWindow::on_BTNRoot_clicked - Handler for the square root button
 */
void MainWindow::on_BTNRoot_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    QString text = ui->output->text();

    if (!text.isEmpty()) {
        bool operatorIn = false;

        // Check if expression contains an operator
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == '+' || text[i] == '-' || text[i] == 'X' || text[i] == char(0x00F7)) {
                operatorIn = true;
                break;
            }
        }

        // Calculate square root if no operator present
        if (operatorIn == false) {
            double value = text.toDouble();
            value = sqrt(value);

            // Check if result is too small
            if (std::abs(value) < 1e-13) {
                ui->output->setText("Number too small!");
                return;
            }

            // Format with fixed precision
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(13) << value;
            std::string str = stream.str();

            // Remove trailing zeros
            str.erase(str.find_last_not_of('0') + 1, std::string::npos);

            // Remove decimal point if it's the last character
            if (!str.empty() && str.back() == '.') {
                str.pop_back();
            }

            QString string2 = QString::fromStdString(str);
            ui->output->setText(string2);

            // Update calculation history
            QString new_output;
            new_output += QChar(0x221A);  // Square root symbol
            new_output += '(';
            new_output += text;
            new_output += ")=";
            new_output += string2;
            ChangeHistory(new_output);
        }
    }
}

/**
 * @brief MainWindow::on_BTNSquared_clicked - Handler for the square button
 */
void MainWindow::on_BTNSquared_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    QString text = ui->output->text();

    if (!text.isEmpty()) {
        bool operatorIn = false;

        // Check if expression contains an operator
        for (int i = 1; i < text.length(); ++i) {
            if (text[i] == '+' || text[i] == '-' || text[i] == 'X' || text[i] == char(0x00F7)) {
                operatorIn = true;
                break;
            }
        }

        // Calculate square if no operator present
        if (operatorIn == false) {
            double value = text.toDouble();
            value = pow(value, 2);

            // Check if result is too big
            if (std::abs(value) > 1e13) {
                ui->output->setText("Number too big!");
                return;
            }

            // Format with fixed precision
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(13) << value;
            std::string str = stream.str();

            // Remove trailing zeros
            str.erase(str.find_last_not_of('0') + 1, std::string::npos);

            // Remove decimal point if it's the last character
            if (!str.empty() && str.back() == '.') {
                str.pop_back();
            }

            QString string2 = QString::fromStdString(str);
            ui->output->setText(string2);

            // Update calculation history
            QString new_output;
            new_output += text;
            new_output += QChar(0x00B2);  // Squared symbol
            new_output += '=';
            new_output += string2;
            ChangeHistory(new_output);
        }
    }
}

/**
 * @brief MainWindow::on_BTNInverse_clicked - Handler for the inverse (1/x) button
 */
void MainWindow::on_BTNInverse_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    QString text = ui->output->text();
    if (!text.isEmpty()) {
        bool operatorIn = false;

        // Check if expression contains an operator
        for (int i = 1; i < text.length(); ++i) {
            if (text[i] == '+' || text[i] == '-' || text[i] == 'X' || text[i] == char(0x00F7)) {
                operatorIn = true;
                break;
            }
        }

        // Calculate inverse if no operator present
        if (operatorIn == false) {
            double value = text.toDouble();
            value = 1/value;

            // Check if result is too small
            if (std::abs(value) < 1e-13) {
                ui->output->setText("Number too small!");
                return;
            }

            // Format with fixed precision
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(13) << value;
            std::string str = stream.str();

            // Remove trailing zeros
            str.erase(str.find_last_not_of('0') + 1, std::string::npos);

            // Remove decimal point if it's the last character
            if (!str.empty() && str.back() == '.') {
                str.pop_back();
            }

            QString string2 = QString::fromStdString(str);
            ui->output->setText(string2);

            // Update calculation history
            QString new_output;
            new_output += "1/";
            new_output += text;
            new_output += '=';
            new_output += string2;
            ChangeHistory(new_output);
        }
    }
}

/**
 * @brief MainWindow::on_BTNPercent_clicked - Handler for the percentage button
 */
void MainWindow::on_BTNPercent_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    QString text = ui->output->text();

    if (!text.isEmpty()) {
        bool operatorIn = false;

        // Check if expression contains an operator
        for (int i = 1; i < text.length(); ++i) {
            if (text[i] == '+' || text[i] == '-' || text[i] == 'X' || text[i] == char(0x00F7)) {
                operatorIn = true;
                break;
            }
        }

        // Calculate percentage if no operator present
        if (operatorIn == false) {
            double value = text.toDouble();
            value = value * .001;  // Convert to percentage (divide by 100)

            // Format with fixed precision
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(13) << value;
            std::string str = stream.str();

            // Check if all digits after decimal are zeros
            bool condition = true;
            int index = 0;
            for (int i = 0; i <= str.size(); ++i) {
                if (str[i] == '.') {
                    index = i;
                    break;
                }
            }

            for (int i = index + 1; i < str.size(); ++i) {
                if (str[i] != '0') {
                    condition = true;
                    break;
                } else {
                    condition = false;
                }
            }

            // Check if number is too small to display
            if (condition == false) {
                ui->output->setText("Number too small!");
            } else {
                // Remove trailing zeros
                str.erase(str.find_last_not_of('0') + 1, std::string::npos);

                // Remove decimal point if it's the last character
                if (!str.empty() && str.back() == '.') {
                    str.pop_back();
                }

                QString string2 = QString::fromStdString(str);
                ui->output->setText(string2);

                // Update calculation history
                QString new_output;
                new_output += text;
                new_output += '%';
                new_output += '=';
                new_output += string2;
                ChangeHistory(new_output);
            }
        }
    }
}

/**
 * @brief MainWindow::on_BTNSign_clicked - Handler for the sign change (+/-) button
 */
void MainWindow::on_BTNSign_clicked()
{
    QString string1 = ui->output->text();

    // Clear error messages if present
    if (string1 == "Number too small!" || string1 == "Number too big!") {
        ui->output->clear();
    }

    QString text = ui->output->text();

    if (!text.isEmpty()) {
        std::vector<QString> vector2 = Split1(text);

        // Change sign of the last number in the expression
        if (vector2[int(vector2.size()) - 1] != '+' &&
            vector2[int(vector2.size()) - 1] != '-' &&
            vector2[int(vector2.size()) - 1] != 'X' &&
            vector2[int(vector2.size()) - 1] != char(0x00F7)) {

            double number = vector2[int(vector2.size()) - 1].toDouble();
            number = number * -1;
            QString result = QString::number(number);
            vector2[int(vector2.size()) - 1] = result;

            // Reconstruct the expression with new sign
            result = "";
            for (int i = 0; i < vector2.size(); ++i) {
                result += vector2[i];
            }
            ui->output->setText(result);
        }
    }
}

// =============================================
// MEMORY FUNCTIONS
// =============================================

/**
 * @brief MainWindow::on_MemoryClear_clicked - Clears all memory registers
 */
void MainWindow::on_MemoryClear_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();

    // Clear all memory registers
    for (int i = 0; i < lineedits.size(); ++i) {
        lineedits[i]->clear();
    }
}

/**
 * @brief MainWindow::on_MemoryAdd_clicked - Adds current value to memory
 */
void MainWindow::on_MemoryAdd_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();

    QString text = ui->output->text();
    bool good;
    double value = text.toDouble(&good);

    // Process only if there's a valid number
    if (good == true) {
        if (lineedits[0]->text().isEmpty()) {
            // If memory is empty, just store the value
            QString new_text = QString::number(value);
            lineedits[0]->setText(new_text);
        } else {
            // If memory has a value, add current value to it
            QString new_text = ui->Memory1->text();
            new_text += '+';
            new_text += ui->output->text();

            // Evaluate the addition
            QJSEngine engine;
            QJSValue result = engine.evaluate(new_text);
            QString output = result.toString();
            ui->Memory1->setText(output);
        }
    }
}

/**
 * @brief MainWindow::on_MemorySub_clicked - Subtracts current value from memory
 */
void MainWindow::on_MemorySub_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();

    QString text = ui->output->text();
    bool good;
    double value = text.toDouble(&good);

    // Process only if there's a valid number
    if (good == true) {
        if (lineedits[0]->text().isEmpty()) {
            // If memory is empty, just store the value
            QString new_text = QString::number(value);
            lineedits[0]->setText(new_text);
        } else {
            // If memory has a value, subtract current value from it
            QString new_text = ui->Memory1->text();
            new_text += '-';
            new_text += ui->output->text();

            // Evaluate the subtraction
            QJSEngine engine;
            QJSValue result = engine.evaluate(new_text);
            QString output = result.toString();
            ui->Memory1->setText(output);
        }
    }
}

/**
 * @brief MainWindow::on_MemoryRecall_clicked - Recalls value from memory
 */
void MainWindow::on_MemoryRecall_clicked()
{
    // Get value from first memory register and display it
    QString new_text = ui->Memory1->text();
    ui->output->setText(new_text);
}

/**
 * @brief MainWindow::on_MemoryStore_clicked - Stores current value to memory
 */
void MainWindow::on_MemoryStore_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();

    // Shift all memory entries down one position
    for (int i = int(lineedits.size()) - 1; i >= 0; --i) {
        if (i == int(lineedits.size()) - 1) {
            lineedits[i]->clear();
        } else if (i == 0) {
            if (lineedits[i]->text().isEmpty()) {
                lineedits[i]->setText(ui->output->text());
            } else {
                QString moving = lineedits[i]->text();
                lineedits[i+1]->setText(moving);
                lineedits[i]->setText(ui->output->text());
            }
        } else {
            QString moving = lineedits[i]->text();
            lineedits[i+1]->setText(moving);
        }
    }
}

// =============================================
// HISTORY FUNCTIONS
// =============================================

/**
 * @brief MainWindow::on_HistoryClear_clicked - Clears calculation history
 */
void MainWindow::on_HistoryClear_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();

    // Clear all history entries
    for (int i = 0; i < lineedits.size(); ++i) {
        lineedits[i]->clear();
    }
}

/**
 * @brief MainWindow::on_BTNEntryClear_2_clicked - Recalls 1st history entry
 */
void MainWindow::on_BTNEntryClear_2_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();
    QString string1 = lineedits[0]->text();

    // Find the equals sign and extract the result
    int index = 0;
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] == '=') {
            index = i;
        }
    }

    // Display the result part of the history entry
    string1.remove(0, index + 1);
    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_3_clicked - Recalls 2nd history entry
 */
void MainWindow::on_BTNEntryClear_3_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();
    QString string1 = lineedits[1]->text();

    // Find the equals sign and extract the result
    int index = 0;
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] == '=') {
            index = i;
        }
    }

    // Display the result part of the history entry
    string1.remove(0, index + 1);
    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_4_clicked - Recalls 3rd history entry
 */
void MainWindow::on_BTNEntryClear_4_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();
    QString string1 = lineedits[2]->text();

    // Find the equals sign and extract the result
    int index = 0;
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] == '=') {
            index = i;
        }
    }

    // Display the result part of the history entry
    string1.remove(0, index + 1);
    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_5_clicked - Recalls 4th history entry
 */
void MainWindow::on_BTNEntryClear_5_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();
    QString string1 = lineedits[3]->text();

    // Find the equals sign and extract the result
    int index = 0;
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] == '=') {
            index = i;
        }
    }

    // Display the result part of the history entry
    string1.remove(0, index + 1);
    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_6_clicked - Recalls 5th history entry
 */
void MainWindow::on_BTNEntryClear_6_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();
    QString string1 = lineedits[4]->text();

    // Find the equals sign and extract the result
    int index = 0;
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] == '=') {
            index = i;
        }
    }

    // Display the result part of the history entry
    string1.remove(0, index + 1);
    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_7_clicked - Recalls 6th history entry
 */
void MainWindow::on_BTNEntryClear_7_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();
    QString string1 = lineedits[5]->text();

    // Find the equals sign and extract the result
    int index = 0;
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] == '=') {
            index = i;
        }
    }

    // Display the result part of the history entry
    string1.remove(0, index + 1);
    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_8_clicked - Recalls 7th history entry
 */
void MainWindow::on_BTNEntryClear_8_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();
    QString string1 = lineedits[6]->text();

    // Find the equals sign and extract the result
    int index = 0;
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] == '=') {
            index = i;
        }
    }

    // Display the result part of the history entry
    string1.remove(0, index + 1);
    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_9_clicked - Recalls 8th history entry
 */
void MainWindow::on_BTNEntryClear_9_clicked()
{
    QList<QLineEdit*> lineedits = ui->History->findChildren<QLineEdit*>();
    QString string1 = lineedits[7]->text();

    // Find the equals sign and extract the result
    int index = 0;
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] == '=') {
            index = i;
        }
    }

    // Display the result part of the history entry
    string1.remove(0, index + 1);
    ui->output->setText(string1);
}

// =============================================
// MEMORY RECALL FUNCTIONS
// =============================================

/**
 * @brief MainWindow::on_BTNEntryClear_10_clicked - Recalls 1st memory value
 */
void MainWindow::on_BTNEntryClear_10_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();
    QString string1 = lineedits[0]->text();

    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_11_clicked - Recalls 2nd memory value
 */
void MainWindow::on_BTNEntryClear_11_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();
    QString string1 = lineedits[1]->text();

    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_12_clicked - Recalls 3rd memory value
 */
void MainWindow::on_BTNEntryClear_12_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();
    QString string1 = lineedits[2]->text();

    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_13_clicked - Recalls 4th memory value
 */
void MainWindow::on_BTNEntryClear_13_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();
    QString string1 = lineedits[3]->text();

    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_14_clicked - Recalls 5th memory value
 */
void MainWindow::on_BTNEntryClear_14_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();
    QString string1 = lineedits[4]->text();

    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_15_clicked - Recalls 6th memory value
 */
void MainWindow::on_BTNEntryClear_15_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();
    QString string1 = lineedits[5]->text();

    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_16_clicked - Recalls 7th memory value
 */
void MainWindow::on_BTNEntryClear_16_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();
    QString string1 = lineedits[6]->text();

    ui->output->setText(string1);
}

/**
 * @brief MainWindow::on_BTNEntryClear_17_clicked - Recalls 8th memory value
 */
void MainWindow::on_BTNEntryClear_17_clicked()
{
    QList<QLineEdit*> lineedits = ui->Memory->findChildren<QLineEdit*>();
    QString string1 = lineedits[7]->text();

    ui->output->setText(string1);
}
