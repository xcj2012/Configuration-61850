#ifndef USERDEFINEDEDELEGATE_H
#define USERDEFINEDEDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QSpinBox>
#include<QCheckBox>
#include <QLineEdit>
#include<QTableWidgetItem>
#include <QRegExpValidator> 
class SubNetTypeCombobox:public QItemDelegate
{
    Q_OBJECT

public:
    SubNetTypeCombobox(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class DataSetListCombox:public QItemDelegate
{
    Q_OBJECT

public:
    DataSetListCombox(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;
    QStringList DatasetList;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class GOOSETypeCombox:public QItemDelegate
{
    Q_OBJECT

public:
    GOOSETypeCombox(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class BOOLTypeCombox:public QItemDelegate
{
    Q_OBJECT

public:
    BOOLTypeCombox(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class YES_NOCombox :public QItemDelegate
{
	Q_OBJECT

public:
	YES_NOCombox(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class BOOLCheckBox:public QItemDelegate
{
    Q_OBJECT

public:
    BOOLCheckBox(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class CheckBoxName :public QItemDelegate
{
	Q_OBJECT

public:
	CheckBoxName(QObject *parent = 0);
    //QString strName;
	
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;
	
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setEditorName(QWidget *editor, const QModelIndex &index,QString name) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;
	QVariant  data(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class CheckBoxModel : public QAbstractTableModel
{
public:
        CheckBoxModel(QObject *parent = 0);

        bool setData( const QModelIndex &index, const QVariant &value, int role );

        QVariant data(const QModelIndex &index, int role) const;
        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        Qt::ItemFlags flags(const QModelIndex &index) const;
        void setrowcount(int row);
        void setcolumncount(int column);
		QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	
private:
        QMap <int, int> check_state_map;
		QMap <int, QString> Name_map;
		QMap <int, QString> Desc_map;
        int rowcount;
        int columncount;
		QStringList  header;
		void populateModel();
};
class CtModelBox:public QItemDelegate
{
    Q_OBJECT

public:
    CtModelBox(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class BatchImportModel : public QAbstractTableModel
{
public:
        BatchImportModel(QObject *parent = 0);

        bool setData( const QModelIndex &index, const QVariant &value, int role );

        QVariant data(const QModelIndex &index, int role) const;
		int rowCount(const QModelIndex &parent) const;
		int columnCount(const QModelIndex &parent) const;
        Qt::ItemFlags flags(const QModelIndex &index) const;
        void setrowcount(int row);
        void setcolumncount(int column);
        QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
        QMap <int, int> check_state_map;
        QMap <int, QString> Name_map;
        QMap <int, QString> File_map;
        QMap <int, QString> Error_map;
        QMap <int, QColor> Color_map;
        int rowcount;
        int columncount;
        QStringList  header;
        void populateModel();
};
class BatchExport : public QAbstractTableModel
{
public:
        BatchExport(QObject *parent = 0);

        bool setData( const QModelIndex &index, const QVariant &value, int role );

        QVariant data(const QModelIndex &index, int role) const;
        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        Qt::ItemFlags flags(const QModelIndex &index) const;
        void setrowcount(int row);
        void setcolumncount(int column);
        QVariant headerData(int section, Qt::Orientation orientation, int role) const;
        void SetHeaderList(QStringList List);
private:
        QMap <int, int> check_state_map;
        QMap <int, QString> Name_map;
        QMap <int, QString> Type_map;
        QMap <int, QString> Vendor_map;
        QMap <int, QString> Desc_map;
        QMap <int, QString> File_map;
        int rowcount;
        int columncount;
        QStringList  header;

};
class EditerItem :public QItemDelegate
{
	Q_OBJECT

public:
	EditerItem(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class APPIDEditer:public QItemDelegate
{
	Q_OBJECT

public:
	APPIDEditer(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class VLANEditer :public QItemDelegate
{
	Q_OBJECT

public:
	VLANEditer(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class MACEditer :public QItemDelegate
{
	Q_OBJECT

public:
	MACEditer(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class IPEditer :public QItemDelegate
{
	Q_OBJECT

public:
	IPEditer(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class ListCombox:public QItemDelegate
{
    Q_OBJECT

public:
    ListCombox(QObject *parent = 0);
    QStringList list;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // 
