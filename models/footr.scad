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

leg_width = 28;
thickness = 5;
$fn = 32;

union() {
    difference() {
        union() {
            translate([0, 0, -thickness/2]) cube([leg_width+4*2, 30, thickness], center=true);
            translate([0, 7.5, 10/2]) union() {
                cube([leg_width+4*2, 15, 10], center=true);
                translate([0, 0, 5]) rotate([0, 90, 0]) cylinder(r = 15/2, h = leg_width+4*2, center = true);
            }
        }
        union() {
            translate([0, 7.5, 20/2]) cube([leg_width, 15+2*2, 20+2*2], center=true);
            translate([-leg_width/2-1, 7.5, 10-14/2]) cube([2+0.01, 3.25, 14], center=true);
            translate([-leg_width/2-1, 7.5, 10]) rotate([0, 90, 0]) cylinder(r = 3, h = 2+0.01, center = true);
        }
    }
    translate([leg_width/2, 7.5, 10]) sphere(r = 3-0.05);
    translate([0, -30/2, -5/2]) rotate([0, 90, 0]) cylinder(r = 5/2, h = leg_width+4*2, center = true);
}