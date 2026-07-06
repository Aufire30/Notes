-- Staff Manager Database Schema
-- Creates location, department, and employee tables with sample data

-- Location table
CREATE TABLE location (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(40) NOT NULL
);

-- Department table
CREATE TABLE department (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(40) NOT NULL,
    locationid INTEGER NOT NULL,
    FOREIGN KEY (locationid) REFERENCES location(id)
);

-- Employee table
CREATE TABLE employee (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(40) NOT NULL,
    departmentid INTEGER NOT NULL,
    extension INTEGER NOT NULL,
    email VARCHAR(40) NOT NULL,
    startdate DATE NOT NULL,
    FOREIGN KEY (departmentid) REFERENCES department(id)
);

-- Insert sample location data
INSERT INTO location (name) VALUES ('The Shed, Elmtree Drive, Boston, MA');
INSERT INTO location (name) VALUES ('Floor 18, 1129 Evanston Heights, New York, NY');
INSERT INTO location (name) VALUES ('14 Valentine Buildings, Amor Street, Cambridge, MA');

-- Insert sample department data
INSERT INTO department (name, locationid) VALUES ('Marketing', 1);
INSERT INTO department (name, locationid) VALUES ('Processing', 2);
INSERT INTO department (name, locationid) VALUES ('Research', 3);
INSERT INTO department (name, locationid) VALUES ('Sales', 2);
INSERT INTO department (name, locationid) VALUES ('Support', 2);

-- Insert sample employee data
INSERT INTO employee (name, departmentid, extension, email, startdate)
VALUES ('Claudia Mendel', 1, 438, 'claudia.mendel@company.com', '2013-09-15');

INSERT INTO employee (name, departmentid, extension, email, startdate)
VALUES ('Digby Roson', 1, 444, 'digby.roson@company.com', '2012-03-20');

INSERT INTO employee (name, departmentid, extension, email, startdate)
VALUES ('Jan Covington', 1, 424, 'jan.covington@company.com', '2014-01-10');

INSERT INTO employee (name, departmentid, extension, email, startdate)
VALUES ('Jordyn-Leigh Lamant', 1, 402, 'jordyn-leigh.lamant@company.com', '2013-11-05');

INSERT INTO employee (name, departmentid, extension, email, startdate)
VALUES ('Ahmed Hanmer', 5, 444, 'ahmed.hanmer@company.com', '2014-01-27');

INSERT INTO employee (name, departmentid, extension, email, startdate)
VALUES ('John Smith', 2, 301, 'john.smith@company.com', '2012-06-15');

INSERT INTO employee (name, departmentid, extension, email, startdate)
VALUES ('Sarah Johnson', 3, 205, 'sarah.johnson@company.com', '2013-08-22');

INSERT INTO employee (name, departmentid, extension, email, startdate)
VALUES ('Mike Wilson', 4, 310, 'mike.wilson@company.com', '2014-02-14');
