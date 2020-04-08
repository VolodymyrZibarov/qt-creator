/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include "gccparser.h"
#include "task.h"

#include <QRegularExpression>

namespace ProjectExplorer {

class PROJECTEXPLORER_EXPORT ClangParser : public ProjectExplorer::GccParser
{
    Q_OBJECT

public:
    ClangParser();

    static QList<IOutputParser *> clangParserSuite();

    static Core::Id id();

private:
    Status doHandleLine(const QString &line, Utils::OutputFormat type) override;

    QRegularExpression m_commandRegExp;
    QRegularExpression m_inLineRegExp;
    QRegularExpression m_messageRegExp;
    QRegularExpression m_summaryRegExp;
    QRegularExpression m_codesignRegExp;
    bool m_expectSnippet;
};

} // namespace ProjectExplorer
