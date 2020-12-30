CREATE DATABASE my_db
    WITH 
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'ru_RU.UTF-8'
    LC_CTYPE = 'ru_RU.UTF-8'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1;

\c my_db;

CREATE TABLE IF NOT EXISTS car ( 
    id_car serial PRIMARY KEY, 
    car_number varchar(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS types_payment (
    id_payment_type serial PRIMARY KEY,
    payment_type_title varchar(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS shipment_status (
    id_shipment_status serial PRIMARY KEY,
    shipment_status_title varchar(30) NOT NULL
);

CREATE TABLE IF NOT EXISTS customer_type (
    id_customer_type serial PRIMARY KEY,
    customer_type_title varchar(30) NOT NULL
);

CREATE TABLE IF NOT EXISTS staff_position ( 
    id_position serial PRIMARY KEY, 
    position_title varchar(50) NOT NULL 
);

CREATE TABLE IF NOT EXISTS payment_organization ( 
    id_payment_organization serial PRIMARY KEY, 
    payment_organization_name varchar(50) NOT NULL 
);

CREATE TABLE IF NOT EXISTS product ( 
    id_product serial PRIMARY KEY, 
    name_product varchar(100), 
    fabrication_price integer, 
    selling_price integer 
);

CREATE TABLE IF NOT EXISTS delivery_point ( 
    id_delivery_point serial PRIMARY KEY, 
    address_delivery_point varchar(200), 
    address_entrance varchar(20), 
    address_password varchar(20), 
    floor_number varchar(10), 
    has_elevator boolean 
);

CREATE TABLE IF NOT EXISTS staff ( 
    id_staff serial PRIMARY KEY, 
    id_position integer NOT NULL REFERENCES staff_position(id_position), 
    staff_name varchar(100) NOT NULL
);

CREATE TABLE IF NOT EXISTS customer ( 
    id_customer serial PRIMARY KEY,
    id_customer_type integer NOT NULL REFERENCES customer_type(id_customer_type), 
    customer_name varchar(100) NOT NULL, 
    customer_address varchar(200), 
    customer_phone_number varchar(20), 
    customer_fax varchar(20), 
    customer_email varchar(100) 
);

CREATE TABLE IF NOT EXISTS payment ( 
    id_payment serial PRIMARY KEY, 
    id_payment_type integer NOT NULL REFERENCES types_payment(id_payment_type), 
    id_payment_organization integer NOT NULL REFERENCES payment_organization(id_payment_organization), 
    account_number varchar(50), 
    payment_bic varchar(50), 
    payment_inn varchar(50), 
    payment_okonx varchar(50), 
    payment_okpo varchar(50) 
);

CREATE TABLE IF NOT EXISTS order_info ( 
    id_order serial PRIMARY KEY, 
    id_delivery_point integer REFERENCES delivery_point(id_delivery_point), 
    id_manager integer REFERENCES staff(id_staff), 
    id_customer integer NOT NULL REFERENCES customer(id_customer), 
    id_payment integer REFERENCES payment(id_payment), 
    order_number varchar(50) NOT NULL UNIQUE, 
    order_price integer NOT NULL, 
    order_discounted_amount integer NOT NULL 
);

CREATE TABLE IF NOT EXISTS order_list ( 
    id_order integer NOT NULL REFERENCES order_info(id_order), 
    id_product integer NOT NULL REFERENCES product(id_product)
);

CREATE TABLE IF NOT EXISTS shipment ( 
    id_shipment serial PRIMARY KEY, 
    id_order integer NOT NULL REFERENCES order_info(id_order), 
    id_car integer REFERENCES car(id_car), 
    id_forwarder integer NOT NULL REFERENCES staff(id_staff), 
    id_shipment_status integer NOT NULL REFERENCES shipment_status(id_shipment_status),
    date_of_receipt TIME, 
    date_planned_completion TIME, 
    date_actual_completion TIME, 
    date_shipping TIME 
);

create view car_v as
    select car.id_car, car.car_number as "Номер машины" from car;

create view types_payment_v as
    select  types_payment.id_payment_type, types_payment.payment_type_title as "Тип оплаты" from types_payment;

create view shipment_status_v as
    select shipment_status.id_shipment_status, shipment_status.shipment_status_title as "Статус заказа" from shipment_status;

create view customer_type_v as
    select customer_type.id_customer_type, customer_type.customer_type_title as "Тип покупателя" from customer_type;

create view staff_position_v as
    select staff_position.id_position, staff_position.position_title as "Должность" from staff_position;

create view payment_organization_v as
    select payment_organization.id_payment_organization, payment_organization.payment_organization_name as
        "Наименование организации" from payment_organization;

create view product_v as
    select product.id_product, product.name_product as "Название продукта",
           product.fabrication_price as "Цена производителя", product.selling_price as "Цена продажи" from product;

create view delivery_point_v as
    select delivery_point.id_delivery_point, delivery_point.address_delivery_point as "Адрес доставки",
           delivery_point.address_entrance as "Номер подъезда", delivery_point.address_password as "Пароль домофона",
           delivery_point.floor_number as "Этаж", delivery_point.has_elevator as "Есть лифт" from delivery_point;

create view staff_v as
    select staff.id_staff, staff_position.position_title as "Должность", staff.staff_name as "ФИО" from staff
        join staff_position on staff.id_position = staff_position.id_position;

create view customer_v as
    select customer.id_customer, customer_type.customer_type_title as "Тип покупателя",
           customer.customer_name as "ФИО покупателя", customer.customer_address as "Адрес рег. юр. лица",
           customer.customer_phone_number as "Номер телефона", customer.customer_fax as "Факс",
           customer.customer_email as "Email"
    from customer join customer_type on customer.id_customer_type = customer_type.id_customer_type;

create view payment_v as
    select payment.id_payment, types_payment.payment_type_title as "Тип оплаты",
           payment_organization.payment_organization_name as "Наименование организации",
           payment.account_number as "Номер счёта",
           payment.payment_bic as "БИК",
           payment.payment_inn as "ИНН",
           payment.payment_okonx as "ОКОНХ",
           payment.payment_okpo as "ОКПО"
    from payment
        join types_payment on payment.id_payment_type = types_payment.id_payment_type
        join payment_organization on payment.id_payment_organization = payment_organization.id_payment_organization;

create view order_info_v as
    select order_info.id_order, order_info.order_number as "Номер заказа",
           order_info.order_price as "Сумма заказа", order_info.order_discounted_amount as "Сумма со скидкой",
           delivery_point_v."Адрес доставки", delivery_point_v."Номер подъезда",
           delivery_point_v."Этаж", delivery_point_v."Пароль домофона", delivery_point_v."Есть лифт",
           staff.staff_name as "Менеджер", customer.customer_name as "ФИО Покупателя",
           payment_v."Тип оплаты", payment_v."Наименование организации",
           payment_v."Номер счёта", payment_v."БИК", payment_v."ИНН",
           payment_v."ОКОНХ", payment_v."ОКПО"
    from order_info
        join delivery_point_v on order_info.id_delivery_point = delivery_point_v.id_delivery_point
        join staff on order_info.id_manager = staff.id_staff
        join customer on order_info.id_customer = customer.id_customer
        join payment_v on order_info.id_payment = payment_v.id_payment;

create view order_list_v as
    select order_list.id_order, order_list.id_product from order_list;

create view shipment_v as
    select shipment.id_shipment, order_info_v."Номер заказа", order_info_v."ФИО Покупателя", car_v."Номер машины",
           staff.staff_name as "ФИО курьера", shipment_status_v."Статус заказа",
           shipment.date_of_receipt as "Получено", shipment.date_planned_completion as "План. комплектации",
           shipment.date_actual_completion as "Укомплектовано", shipment.date_shipping as "Отгружено" from shipment
        join order_info_v on shipment.id_order = order_info_v.id_order
        join car_v on shipment.id_car = car_v.id_car
        join staff on shipment.id_forwarder = staff.id_staff
        join shipment_status_v on shipment.id_shipment_status = shipment_status_v.id_shipment_status;

