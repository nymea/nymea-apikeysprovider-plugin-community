// SPDX-License-Identifier: GPL-3.0-or-later

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Copyright (C) 2013 - 2024, nymea GmbH
* Copyright (C) 2024 - 2026, chargebyte austria GmbH
*
* This file is part of nymea-apikeysprovider-plugin-community.
*
* nymea-apikeysprovider-plugin-community is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* nymea-apikeysprovider-plugin-community is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with nymea-apikeysprovider-plugin-community. If not, see <https://www.gnu.org/licenses/>.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apikeysproviderstatic.h"
#include "apikeys.h"

#include <QVariant>
#include <QJsonDocument>

#include <loggingcategories.h>
NYMEA_LOGGING_CATEGORY(dcApiKeysProviderStatic, "ApiKeysProviderStatic")

ApiKeysProviderStatic::ApiKeysProviderStatic()
{
    qCDebug(dcApiKeysProviderStatic()) << "Loaded static provider";
}

QHash<QString, ApiKey> ApiKeysProviderStatic::apiKeys() const
{
    QHash<QString, ApiKey> ret;

    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(QByteArray::fromBase64(data), &error);
    if (error.error != QJsonParseError::NoError) {
        qCWarning(dcApiKeysProviderStatic()) << "Error parsing API input file";
        return ret;
    }

    QVariantMap keysMap = jsonDoc.toVariant().toMap();
    foreach (const QString &keyName, keysMap.keys()) {
        QVariantMap keyContent = keysMap.value(keyName).toMap();
        ApiKey key;
        foreach (const QString &entryName, keyContent.keys()) {
            key.insert(entryName, keyContent.value(entryName).toByteArray());
        }
        ret.insert(keyName, key);
    }
    return ret;
}
