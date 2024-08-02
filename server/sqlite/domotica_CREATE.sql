-- Crear tabla AMBIENTES
CREATE TABLE IF NOT EXISTS "ambientes" (
	"am_id" INTEGER NOT NULL UNIQUE,
	"am_nombre" TEXT NOT NULL,
	PRIMARY KEY("am_id")	
);

-- Crear tabla DISPOSITIVOS
CREATE TABLE IF NOT EXISTS "dispositivos" (
	"di_id" INTEGER NOT NULL UNIQUE,
	"di_tipo" TEXT NOT NULL CHECK(di_tipo IN ('sensor', 'actuador')),
	"di_marca" TEXT NOT NULL,
	"di_modelo" TEXT NOT NULL,
	"di_serial" TEXT NOT NULL UNIQUE,
	"di_descripcion" TEXT,
	"di_am_id" INTEGER,
	PRIMARY KEY("di_id"),
	FOREIGN KEY ("di_am_id") REFERENCES "ambientes"("am_id")
	ON UPDATE NO ACTION ON DELETE NO ACTION
);

-- Crear tabla EVENTOS
CREATE TABLE IF NOT EXISTS "eventos" (
	"ev_id" INTEGER NOT NULL UNIQUE,
	"ev_tipo_evento" TEXT NOT NULL,
	"ev_timestamp" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
	"ev_am_id" INTEGER,
	"ev_di_id" INTEGER,
	"ev_valor" REAL,
	"ev_descripcion" TEXT,
	PRIMARY KEY("ev_id"),
	FOREIGN KEY ("ev_am_id") REFERENCES "ambientes"("am_id")
	ON UPDATE NO ACTION ON DELETE NO ACTION
);
