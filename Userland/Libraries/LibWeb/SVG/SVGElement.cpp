/*
 * Copyright (c) 2020, Matthew Olsson <mattco@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/SVG/SVGElement.h>

namespace Web::SVG {

SVGElement::SVGElement(DOM::Document& document, DOM::QualifiedName qualified_name)
    : Element(document, move(qualified_name))
    , m_dataset(HTML::DOMStringMap::create(*this))
{
    set_prototype(&Bindings::cached_web_prototype(realm(), "SVGElement"));
}

void SVGElement::visit_edges(Cell::Visitor& visitor)
{
    Base::visit_edges(visitor);
    visitor.visit(m_dataset.ptr());
}

}
