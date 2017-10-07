/***************************************************************************
**
** Copyright (C) 2017 Jochen Baier
** Contact: email@jochen-baier.
**
** This file is part of the FastWindowSwitcher

This program is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see < http://www.gnu.org/licenses/>.

Dieses Programm ist Freie Software : Sie k�nnen es unter den Bedingungen
der GNU General Public License, wie von der Free Software Foundation,
Version 3 der Lizenz oder(nach Ihrer Wahl) jeder neueren
ver�ffentlichten Version, weiterverbreiten und / oder modifizieren.

Dieses Programm wird in der Hoffnung, dass es n�tzlich sein wird, aber
OHNE JEDE GEW�HRLEISTUNG, bereitgestellt; sogar ohne die implizite
Gew�hrleistung der MARKTF�HIGKEIT oder EIGNUNG F�R EINEN BESTIMMTEN ZWECK.
Siehe die GNU General Public License f�r weitere Details.

Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
Programm erhalten haben.Wenn nicht, siehe < http://www.gnu.org/licenses/>.
******************************************************************************/

#pragma once

#include <QObject>

#include "Session.hpp"
#include "HiddenEventWindow.hpp"
#include "TrayIcon.hpp"
#include "PersistentSettings.hpp"
#include "SettingsWindow.hpp"

class QTimer;

namespace FastWindowSwitcher
{
  class SessionManager : public QObject
  {
    Q_OBJECT

  public:
    explicit SessionManager();
    void ReCreateSession();
    void CreateFirstSession();

    Q_SLOT void ReCreateSessionDelayed();
    Q_SLOT void Shutdown();

  private:
    Q_SLOT void ShowSettingsDialog();
    void RegisterGlobalHotkeyDisplayWarningOnError();
    
    PersistenSettings m_persistentSettings;
    QString m_settingsFile;
    HiddenEventWindowPtr m_hiddenEventWindow;
    QTimer* m_recreateTimer;
    SessionPtr m_session;
    TrayIconPtr m_trayIcon;
    bool m_settingsWindowIsOpen = false;
   
  };

};

