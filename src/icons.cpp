#include "icons.hpp"

#include <QHash>

// Static definition
QHash<QString, QString> Icons::iconNames = QHash<QString, QString>();

Icons::Icons()
{
	if (iconNames.isEmpty())
	{
		iconNames = {
			// File menu
			{ "file-new",				"document-new"				},
			{ "file-open",				"document-open"				},
			{ "file-save-as",			"document-save-as"			},
			{ "file-quit",				"exit"						},
			// Edit menu
			{ "edit-rename",				"text-field"					},
			{ "edit-reload",				"reload"						},
			// About menu
			{ "about-app",				"help-about"					},
			{ "about-qt",				"qt"							},
			{ "about-licenses",			"license"					},
			{ "about-update",			"download"					},
			// Tools
			{ "tools-move",				"object-move-symbolic"		},
			{ "tools-link",				"draw-line"					},
			// Other menus
			{ "menu-edit",				"document-edit"				},
			{ "menu-delete",				"delete"						},
			// Text formatting
			{ "format-bold",				"format-text-bold"			},
			{ "format-italic",			"format-text-italic"			},
			{ "format-underline",		"format-text-underline"		},
			{ "format-strikethrough",	"format-text-strikethrough"	},
			// Validation engine
			{ "validate-ok",				"emblem-checked"				},
			{ "validate-fail",			"emblem-error"				},
			{ "validate-disabled",		"emblem-pause"				},
			{ "validate-none",			"emblem-question"			},
		};
	}
}

QIcon Icons::get(const QString &name)
{
	// For now, this is linux only
	return QIcon::fromTheme(iconNames.value(name));
}
