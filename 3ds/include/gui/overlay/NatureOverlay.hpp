/*
 *   This file is part of PKSM
 *   Copyright (C) 2016-2019 Bernardo Giordano, Admiral Fish, piepie62
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
 *       * Requiring preservation of specified reasonable legal notices or
 *         author attributions in that material or in the Appropriate Legal
 *         Notices displayed by works containing it.
 *       * Prohibiting misrepresentation of the origin of that material,
 *         or requiring that modified versions of such material be marked in
 *         reasonable ways as different from the original version.
 */

#ifndef NATURESELECTIONSCREEN_HPP
#define NATURESELECTIONSCREEN_HPP

#include "HidHorizontal.hpp"
#include "Overlay.hpp"
#include "PKX.hpp"
#include "i18n.hpp"

class NatureOverlay : public Overlay
{
public:
    NatureOverlay(Screen& screen, std::shared_ptr<PKX> pkm)
        : Overlay(screen, i18n::localize("A_SELECT") + '\n' + i18n::localize("B_BACK")), pkm(pkm), hid(25, 5)
    {
        hid.update(25);
        hid.select(pkm->nature());
    }
    NatureOverlay(Overlay& ovly, std::shared_ptr<PKX> pkm)
        : Overlay(ovly, i18n::localize("A_SELECT") + '\n' + i18n::localize("B_BACK")), pkm(pkm), hid(25, 5)
    {
        hid.update(25);
        hid.select(pkm->nature());
    }
    virtual ~NatureOverlay() {}
    void drawTop() const override;
    bool replacesTop() const override { return true; }
    void drawBottom() const override;
    void update(touchPosition* touch) override;

private:
    std::shared_ptr<PKX> pkm;
    HidHorizontal hid;
};

#endif
