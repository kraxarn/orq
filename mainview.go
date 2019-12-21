package main

import (
	"fmt"
	"math/rand"

	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/widgets"
)

type Line struct {
	parent uint64
	child  uint64
	line   *widgets.QGraphicsLineItem
}

var links map[uint64][]*Line

var view *widgets.QGraphicsView

func CreateView(window *widgets.QMainWindow, linkRadio *widgets.QRadioButton) *widgets.QGraphicsView {
	// Create scene and view
	scene := widgets.NewQGraphicsScene(nil)
	view = widgets.NewQGraphicsView2(scene, nil)

	// Add example item
	view.SetAcceptDrops(true)
	view.SetAlignment(core.Qt__AlignTop | core.Qt__AlignLeft)
	view.ConnectDragMoveEvent(func(event *gui.QDragMoveEvent) {
		if event.Source() != nil {
			event.AcceptProposedAction()
		}
	})
	// ID of item to add next
	var itemID int
	// What item we're currently moving, if any
	var movingItem *widgets.QGraphicsItemGroup
	// Start position of link
	var linkStart *widgets.QGraphicsItemGroup

	itemSize := 64.0
	view.ConnectDropEvent(func(event *gui.QDropEvent) {
		pos := view.MapToScene(event.Pos())
		scene.AddItem(AddGraphicsItem(view, fmt.Sprintf("Item %v", itemID), pos.X()-(itemSize/2.0), pos.Y()-(itemSize/2.0), itemSize, itemSize))
		itemID = itemID + 1
	})

	view.ConnectMousePressEvent(func(event *gui.QMouseEvent) {
		if event.Button() != core.Qt__LeftButton {
			return
		}
		item := view.ItemAt(event.Pos())
		// If an item was found
		if item != nil && item.Group() != nil {
			if linkRadio.IsChecked() {
				// We're creating a link
				linkStart = item.Group()

			} else {
				// We're moving an item
				movingItem = item.Group()
				movingItem.SetOpacity(0.6)
			}
		}
	})
	view.ConnectMouseMoveEvent(func(event *gui.QMouseEvent) {
		if movingItem != nil {
			movingItem.SetPos(view.MapToScene5(event.Pos().X()-32, event.Pos().Y()-32))
		}
	})
	view.ConnectMouseReleaseEvent(func(event *gui.QMouseEvent) {
		if event.Button() == core.Qt__RightButton {
			// When right clicking item, show edit/delete options
			menu := widgets.NewQMenu(nil)
			// Edit option
			editAction := menu.AddAction2(gui.QIcon_FromTheme("document-edit"), "Edit")
			editAction.ConnectTriggered(func(checked bool) {
				window.AddDockWidget(core.Qt__RightDockWidgetArea, CreateEditWidget())
			})
			// Delete option
			deleteAction := menu.AddAction2(gui.QIcon_FromTheme("delete"), "Delete")
			deleteAction.ConnectTriggered(func(checked bool) {
				// Hakke write ur delete here
			})
			// Show menu at cursor
			menu.Popup(view.MapToGlobal(event.Pos()), nil)
			return
		}

		// We released a button while moving an item
		if movingItem != nil {
			// Update link if needed
			// Error handling is already taken care of in UpdateLinkPos
			UpdateLinkPos(movingItem, movingItem.Pos().X(), movingItem.Pos().Y())
			// Reset opacity and remove as moving
			movingItem.SetOpacity(1.0)
			movingItem = nil
		}

		// We released while creating a link
		if linkStart != nil {
			// If we try to link to the empty void
			if view.ItemAt(event.Pos()).Group() == nil {
				linkStart = nil
				return
			}
			toPos := view.ItemAt(event.Pos()).Group().Pos()
			if toPos.X() == 0 && toPos.Y() == 0 {
				return
			}
			scene.AddItem(AddLink(linkStart, view.ItemAt(event.Pos()).Group()))
			linkStart = nil
		}
	})
	return view
}

func GetGroupUID(group *widgets.QGraphicsItemGroup) uint64 {
	return group.Data(0).ToULongLong(nil)
}

func GetGroupFromUID(id uint64) *widgets.QGraphicsItemGroup {
	// TODO: This needs to be done in a quicker way
	for _, item := range view.Items() {
		if group := item.Group(); group != nil && GetGroupUID(group) == id {
			return group
		}
	}
	return nil
}

func AddLink(parent, child *widgets.QGraphicsItemGroup) *widgets.QGraphicsLineItem {
	// Check if map needs to be created
	if links == nil {
		links = make(map[uint64][]*Line)
	}
	// Get from (parent) and to (child)
	fromPos := parent.Pos()
	toPos := child.Pos()
	// Create graphics line
	line := widgets.NewQGraphicsLineItem3(
		fromPos.X()+32, fromPos.Y()+32,
		toPos.X()+32, toPos.Y()+32,
		nil,
	)
	// Set the color of it
	line.SetPen(gui.NewQPen3(gui.NewQColor3(0, 255, 0, 255)))
	// Create line data
	parentID := GetGroupUID(parent)
	childID := GetGroupUID(child)
	lineData := Line{
		parentID, childID, line,
	}
	links[parentID] = append(links[parentID], &lineData)
	links[childID] = append(links[childID], &lineData)
	// Return the graphics line to add to scene
	return line
}

func GetRandomItemUID() uint64 {
	// TODO: This should guarantee unique, for now, just return random uint64
	return rand.Uint64()
}

func UpdateLinkPos(item *widgets.QGraphicsItemGroup, x, y float64) {
	// Get link
	itemID := GetGroupUID(item)
	link, ok := links[itemID]
	// Error checking
	if !ok {
		return
	}
	for _, l := range link {
		// If the item is the parent
		isParent := l.parent == itemID
		// Update position of either parent or child
		if isParent {
			pos := GetGroupFromUID(l.child).Pos()
			l.line.SetLine2(x+32, y+32, pos.X()+32, pos.Y()+32)
		} else {
			pos := GetGroupFromUID(l.parent).Pos()
			l.line.SetLine2(pos.X()+32, pos.Y()+32, x+32, y+32)
		}
	}
}

func AddGraphicsItem(view *widgets.QGraphicsView, text string, x, y, width, height float64) *widgets.QGraphicsItemGroup {
	group := widgets.NewQGraphicsItemGroup(nil)
	textItem := widgets.NewQGraphicsTextItem2(text, nil)
	shapeItem := widgets.NewQGraphicsRectItem3(0, 0, width, height, nil)
	group.AddToGroup(textItem)
	group.AddToGroup(shapeItem)
	group.SetPos2(x, y)
	group.SetData(0, core.NewQVariant1(GetRandomItemUID()))
	return group
}