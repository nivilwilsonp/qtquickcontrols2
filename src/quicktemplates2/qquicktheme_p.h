/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Quick Templates 2 module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QQUICKTHEME_P_H
#define QQUICKTHEME_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtQuickTemplates2/private/qtquicktemplates2global_p.h>
#include <QtCore/qscopedpointer.h>
#include <QtGui/qfont.h>
#include <QtGui/qpalette.h>

QT_BEGIN_NAMESPACE

class QQuickThemePrivate;

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT QQuickTheme
{
public:
    QQuickTheme();
    virtual ~QQuickTheme();

    static QQuickTheme *current();
    static void setCurrent(QQuickTheme *theme);

    enum Font {
        SystemFont,
        MenuFont,
        MenuBarFont,
        MenuItemFont,
        MessageBoxFont,
        LabelFont,
        TipLabelFont,
        StatusBarFont,
        TitleBarFont,
        MdiSubWindowTitleFont,
        DockWidgetTitleFont,
        PushButtonFont,
        CheckBoxFont,
        RadioButtonFont,
        ToolButtonFont,
        ItemViewFont,
        ListViewFont,
        HeaderViewFont,
        ListBoxFont,
        ComboMenuItemFont,
        ComboLineEditFont,
        SmallFont,
        MiniFont,
        FixedFont,
        GroupBoxTitleFont,
        TabButtonFont,
        EditorFont,
        SwitchFont,
        SpinBoxFont,
        TumblerFont,
        NFonts
    };

    enum Palette {
        SystemPalette,
        ToolTipPalette,
        ToolButtonPalette,
        ButtonPalette,
        CheckBoxPalette,
        RadioButtonPalette,
        HeaderPalette,
        ComboBoxPalette,
        ItemViewPalette,
        MessageBoxLabelPelette,
        MessageBoxLabelPalette = MessageBoxLabelPelette,
        TabBarPalette,
        LabelPalette,
        GroupBoxPalette,
        MenuPalette,
        MenuBarPalette,
        TextEditPalette,
        TextLineEditPalette,
        SpinBoxPalette,
        SwitchPalette,
        TumblerPalette,
        NPalettes
    };

    static QFont themeFont(Font type);
    static QPalette themePalette(Palette type);

protected:
    virtual const QFont *font(Font type) const;
    virtual const QPalette *palette(Palette type) const;

    virtual void resolveFonts(const QFont &defaultFont);
    virtual void resolvePalettes(const QPalette &defaultPalette);

private:
    Q_DISABLE_COPY(QQuickTheme)
    Q_DECLARE_PRIVATE(QQuickTheme)
    QScopedPointer<QQuickThemePrivate> d_ptr;
};

QT_END_NAMESPACE

#endif // QQUICKTHEME_P_H
