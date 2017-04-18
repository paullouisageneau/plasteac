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
servo_height = 19 + 0.5;
servo_width  = 20;
servo_depth  =  9;
servo_side   =  6;
leg_distance = 17.5;
body_radius = 30;
body_border = 2;

difference() {
    union() {
        translate([0, 0, -5]) difference() {
            cylinder(r = body_radius, h = 2);
            cube([32, leg_distance*2+10, 20], center = true);
        }
        translate([0, 0, -3]) difference() {
            cylinder(r = body_radius-body_border-0.25, h = 3);
            cylinder(r = body_radius-body_border-2, h = 20, center = true);
        }
        translate([0, 0, -4]) cube([32, leg_distance*2-10, 2], center = true);
        translate([0,-leg_distance, 0]) support_servo(10, 32);
        translate([0, leg_distance, 0]) support_servo(10, 32);
    }
    union() {
        translate([-(body_radius-body_border)*2/3, 0, 0]) cube([4, 10, 20], center = true);
    }
}
module support_servo(width, depth) {
    $fn = 32;
    union() {
        pad = 5;
        difference() {
            translate([0,0,-pad/2]) cube([depth, width, pad], center=true);
            translate([servo_width/2 - servo_depth/2-0.25, 0, 0]) {
                translate([-4, 0, -servo_height/2]) cylinder(r = 3+0.25, h = 20, center = true);
                translate([0, 0, -servo_height/2]) cylinder(r = servo_depth/2+0.25, h = 20, center = true);
                }
        }
        translate([(servo_width+servo_side)/2, 0, 2.25]) difference() {
            cube([servo_side, servo_depth, 4.5], center = true);
            cylinder(r = 1, h = 10, center = true);
        }
        translate([-(servo_width+servo_side)/2, 0, 2.25]) difference() {
            cube([servo_side, servo_depth, 4.5], center = true);
            cylinder(r = 1, h = 10, center = true);
        }
    }
}
