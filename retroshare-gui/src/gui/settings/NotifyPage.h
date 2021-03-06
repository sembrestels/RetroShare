/****************************************************************
 *  RetroShare is distributed under the following license:
 *
 *  Copyright (C) 2006 - 2009 RetroShare Team
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA  02110-1301, USA.
 ****************************************************************/

#ifndef NOTIFYPAGE_H
#define NOTIFYPAGE_H

#include <retroshare-gui/configpage.h>
#include "ui_NotifyPage.h"

#include "gui/chat/ChatLobbyUserNotify.h"

class UserNotify;
class FeedNotify;
class ToasterNotify;

class UserNotifySetting
{
public:
    UserNotify *mUserNotify;
    QCheckBox *mEnabledCheckBox;
    QCheckBox *mCombinedCheckBox;
    QCheckBox *mBlinkCheckBox;

public:
    UserNotifySetting(UserNotify *userNotify, QCheckBox *enabledCheckBox, QCheckBox *combinedCheckBox, QCheckBox *blinkCheckBox)
        : mUserNotify(userNotify), mEnabledCheckBox(enabledCheckBox), mCombinedCheckBox(combinedCheckBox), mBlinkCheckBox(blinkCheckBox) {}
};

class FeedNotifySetting
{
public:
    FeedNotify *mFeedNotify;
    QCheckBox *mEnabledCheckBox;

public:
    FeedNotifySetting(FeedNotify *feedNotify, QCheckBox *enabledCheckBox)
        : mFeedNotify(feedNotify), mEnabledCheckBox(enabledCheckBox) {}
};

class ToasterNotifySetting
{
public:
    ToasterNotify *mToasterNotify;
    QCheckBox *mEnabledCheckBox;

public:
    ToasterNotifySetting(ToasterNotify *toasterNotify, QCheckBox *enabledCheckBox)
        : mToasterNotify(toasterNotify), mEnabledCheckBox(enabledCheckBox) {}
};

class NotifyPage : public ConfigPage
{
    Q_OBJECT

public:
    /** Default Constructor */
    NotifyPage(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    /** Default Destructor */
    ~NotifyPage();

    /** Saves the changes on this page */
    virtual bool save(QString &errmsg);
    /** Loads the settings for this page */
    virtual void load();

	 virtual QPixmap iconPixmap() const { return QPixmap(":/images/status_unknown.png") ; }
	 virtual QString pageName() const { return tr("Notify") ; }
	 virtual QString helpText() const ;

private slots:
	void notifyToggled();
	void testToaster();
	void testFeed();

private:
	uint getNewsFlags();
	uint getNotifyFlags();
	ChatLobbyUserNotify* mChatLobbyUserNotify;

    QList<FeedNotifySetting> mFeedNotifySettingList;
    QList<ToasterNotifySetting> mToasterNotifySettingList;
    QList<UserNotifySetting> mUserNotifySettingList;

    /** Qt Designer generated object */
    Ui::NotifyPage ui;
};

#endif // !NOTIFYPAGE_H

