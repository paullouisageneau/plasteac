/* 
 * Copyright (c) 2017 by Paul-Louis Ageneau
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

$fn = 90;
body_radius = 30;
body_height = 45.1;
body_border = 2;
teapot_scale = 0.90;

difference() {
    union() {
        scale([1, 1, 1]*teapot_scale) import("utah_teapot.stl", convexity=5);
        cylinder(r = body_radius, h = body_border);
        translate([0, 0, body_height-1]) cylinder(r = body_radius-2, h = 2, center = true);
    }
    union() {
        translate([0, 0, -0.01]) cylinder(r = body_radius-body_border, h = body_height/2);
        translate([0, 0, body_height-1]) cylinder(r1 = body_radius-2, r2 = body_radius-4, h = 2+0.02, center = true);
    }
}

