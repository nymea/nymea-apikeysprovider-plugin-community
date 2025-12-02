// SPDX-License-Identifier: GPL-3.0-or-later

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Copyright (C) 2013 - 2024, nymea GmbH
* Copyright (C) 2024 - 2025, chargebyte austria GmbH
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

#ifndef APIKEYSPROVIDERSTATIC_H
#define APIKEYSPROVIDERSTATIC_H

#include <network/apikeys/apikeysprovider.h>

class ApiKeysProviderStatic : public ApiKeysProvider
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "io.nymea.ApiKeysProviderStatic")
    Q_INTERFACES(ApiKeysProvider)
public:
    explicit ApiKeysProviderStatic();
    ~ApiKeysProviderStatic() override = default;

    QHash<QString, ApiKey> apiKeys() const override;

};

#endif // APIKEYSPROVIDERSTATIC_H
